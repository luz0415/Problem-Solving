#include <iostream>
using namespace std;

int main() {
    int N; cin >> N;

    // 13 > 
    int ans = 100000;

    for (int i = 0; i * 5 <= N; i++)
    {
        if ((N-(i*5)) % 2 == 0)
        {
            ans = min(ans, i + (N-(i*5)) / 2);
        }
    }

    if (ans == 100000) cout << -1;
    else cout << ans;
    return 0;
}