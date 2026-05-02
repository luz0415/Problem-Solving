#include <iostream>
using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;

    int arr[100001] = {};
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    int LMax[100000] = {}, RMax[100000] = {};
    LMax[0] = arr[0];
    for (int i = 1; i < N; i++)
    {
        LMax[i] = max(LMax[i-1], arr[i]);
    }
    RMax[N-1] = arr[N-1];
    for (int i = N-2; i >= 0; i--)
    {
        RMax[i] = max(RMax[i+1], arr[i]);
    }

    for (int i = 0; i < Q; i++)
    {
        int a, b;
        cin >> a >> b;

        if (a == 1) { cout << RMax[b]; }
        else if (b == N) { cout << LMax[a-2]; }
        else { cout << max(LMax[a-2], RMax[b]); }

        cout << '\n';
    }
    return 0;
}
