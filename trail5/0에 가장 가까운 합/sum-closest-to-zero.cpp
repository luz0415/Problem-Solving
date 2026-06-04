#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    int arr[100000] = {};
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr+N);

    int ans = 2e9;

    int L = 0, R = N-1;
    while (L < R)
    {
        ans = min(ans, abs(arr[L]+arr[R]));
        if (arr[L] + arr[R] < 0)
        {
            L++;
        }
        else
        {
            R--;
        }
    }

    cout << ans;
    return 0;
}