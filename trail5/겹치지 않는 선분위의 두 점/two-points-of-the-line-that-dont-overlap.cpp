#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;
using ll = long long;

int N, M;
pair<ll, ll> line[100000];

ll BinarySearch()
{  
    ll L = 1, R = 1e18;
    ll ans = 0;
    while (L <= R)
    {
        ll mid = (L+R) / 2;
        
        int count = (line[0].second - line[0].first) / mid + 1;
        ll cur = line[0].first + (line[0].second - line[0].first) / mid * mid;

        for (int i = 1; i < M; i++)
        {
            ll next = max(cur+mid, line[i].first);
            if (next <= line[i].second)
            {
                ll inLine = (line[i].second - next) / mid;
                count += inLine + 1;
                cur = next + inLine * mid;
            }
        }

        if (count >= N)
        {
            ans = max(mid, ans);
            L = mid + 1;
        }
        else
        {
            R = mid - 1;
        }
    }

    return ans;
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        cin >> line[i].first >> line[i].second;
    }

    sort(line, line+M);

    cout << BinarySearch();

    return 0;
}