#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int arr[100000];
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    int ans = -1000;
    int now = 0;
    for (int i = 0; i < N; i++)
    {
        now = max(now + arr[i], arr[i]);
        ans = max(ans, now);
    }

    cout << ans;
    return 0;
}