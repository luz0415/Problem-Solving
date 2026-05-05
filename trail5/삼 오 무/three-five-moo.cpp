#include <iostream>
using namespace std;
using ll = long long;
int N;

int BinarySearch()
{
    ll L = 1, R = 1e10;
    ll ans = 1e10;

    while (L <= R)
    {
        ll mid = (L+R) / 2;

        ll mooCount = mid / 3 + mid / 5 - mid / 15;
        if (mid - mooCount >= N)
        {
            R = mid - 1;
            if (mid - mooCount == N) { ans = min(ans, mid); }
        }
        else
        {
            L = mid + 1;
        }
    }

    return ans;
}

int main() {
    cin >> N;
    cout << BinarySearch();
    return 0;
}