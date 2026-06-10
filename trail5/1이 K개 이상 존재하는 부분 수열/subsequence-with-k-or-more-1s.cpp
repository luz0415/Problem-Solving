#include <iostream>
using namespace std;

int main() {
    int N, K;
    int arr[1000000] = {};

    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    int ans = 2e9;
    int oneCount = 0;
    int L = 0;
    for (int i = 0; i < N; i++)
    {
        if (arr[i] == 1) { L = i; break; }
    }

    for (int i = 0; i < N; i++)
    {
        if (arr[i] == 1)
        {
            oneCount++;
            if (oneCount == K)
            {
                ans = min(ans, i-L+1);
                
                L++;
                while (arr[L] != 1)
                {
                    L++;
                }
                oneCount--;
            }
        }
    }

    if (ans == 2e9) { cout << -1; }
    else { cout << ans; }
    return 0;
}