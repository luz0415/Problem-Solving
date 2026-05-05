#include <iostream>
using namespace std;
using ll = long long;

int N, M;
int path[100000];

ll BinarySearch()
{
    ll L = 1, R = 1e14;
    ll ans = 1e14;

    while (L <= R)
    {
        ll mid = (L+R) / 2;
        
        ll count = 0;
        for (int i = 0; i < M; i++)
        {
            count += mid / path[i];
        }

        if (count >= N)
        {
            ans = min(ans, mid);
            R = mid - 1;
        }
        else
        {
            L = mid + 1;
        }
    }
    return ans;
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        cin >> path[i];
    }  

    cout << BinarySearch();
    return 0;
}