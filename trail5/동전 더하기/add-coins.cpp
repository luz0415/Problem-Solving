#include <iostream>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    int coin[10] = {};
    for (int i = 0; i < N; i++)
    {
        cin >> coin[i];
    }

    int ans = 0, idx = N-1;
    while (K > 0)
    {
        ans += K / coin[idx];
        K -= coin[idx] * (K / coin[idx]);
        idx--;
    }
    cout << ans;
    return 0;
}