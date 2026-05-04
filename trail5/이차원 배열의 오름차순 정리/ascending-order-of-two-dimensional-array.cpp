#include <iostream>
using namespace std;
using ll = long long;

int N, K;

ll BinarySearch()
{
    ll L = 1, R = 1e10;
    ll num = 1e10;
    while (L <= R)
    {
        ll mid = (L+R) / 2;
        ll nowK = 0;
        for (int i = 1; i <= N; i++)
        {
            nowK += min(mid/i, (ll)N);
        }

        if (nowK >= K)
        {
            R = mid - 1;
            num = min(num, mid);
        }
        else
        {
            L = mid + 1;
        }
    }

    return num;
}

int main() {
    cin >> N >> K;
    cout << BinarySearch();
    return 0;
}