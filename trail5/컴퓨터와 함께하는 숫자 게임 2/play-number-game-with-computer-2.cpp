#include <iostream>
using namespace std;
using ll = long long;

ll M;
ll BinarySearch(ll find)
{
    ll L = 1, R = M;
    ll count = 0;
    while (L <= R)
    {
        ll mid = (L+R) / 2;
        count++;
        if (mid < find)
        {
            L = mid+1;
        }
        else if (mid > find)
        {
            R = mid-1;
        }
        else
        {
            break;
        }
    }
    return count;
}

int main() {
    cin >> M;

    ll A, B;
    cin >> A >> B;

    ll maxCount = 0, minCount = 1e18;
    for (ll i = A; i <= B; i++)
    {
        ll bs = BinarySearch(i);
        minCount = min(minCount, bs);
        maxCount = max(maxCount, bs);
    }

    cout << minCount << ' ' << maxCount;
    return 0;
}