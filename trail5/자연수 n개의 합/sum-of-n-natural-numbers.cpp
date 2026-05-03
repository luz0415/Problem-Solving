#include <iostream>
using namespace std;
using ll = long long;

ll BinarySearch(ll findSum)
{
    ll L = 1, R = 2e9;
    ll maxNum = 0;
    while (L <= R)
    {
        ll mid = (L+R) / 2;
        ll sum = (mid*(mid+1)) / 2;

        if (sum <= findSum)
        {
            maxNum = max(maxNum, mid);
            L = mid + 1;
        }
        else
        {
            R = mid - 1;
        }
    }
    return maxNum;
}

int main() {
    ll S; cin >> S;
    cout << BinarySearch(S);
    return 0;
}