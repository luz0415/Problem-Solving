#include <iostream>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    int arr[1000001] = {};
    for (int i = 0; i < N; i++)
    {
        int a, b; cin >> a >> b;
        arr[b] = a;
    }

    int c = min(K, 1000000);
    int ans = 0, now = arr[c];
    for (int i = 1; i <= K; i++)
    {
        if (c+i <= 1000000) now += arr[c+i];
        if (c-i >= 0) now += arr[c-i];
    }
    ans = now;
    c++;
    for (; c <= 1000000; c++)
    {
        if (c+K <= 1000000) now += arr[c+K];
        if (c-K-1 >= 0) now -= arr[c-K-1];
        ans = max(now, ans);
    }

    cout << ans;
    return 0;
}