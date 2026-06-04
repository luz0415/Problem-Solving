#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    int arr[100001] = {};
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr+N);
    
    int L = 0, R = N-1;
    int ans = 0;
    
    while (L < R)
    {
        if (arr[L] + arr[R] <= K)
        {
            L++;
            ans += R - L + 1;
        }
        else
        {
            R--;
        }
    }

    cout << ans;
    return 0;
}