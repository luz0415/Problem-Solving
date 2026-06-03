#include <iostream>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;


    int arr[100000] = {};
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    int ans = 0;
    int L = 0, R = 0;
    long long now = 0;
    
    while (true)
    {
        if (now >= M)
        {
            if (now == M) ans++;
            now -= arr[L++];
        }
        else if (R == N)
        {
            break;
        }
        else
        {
            now += arr[R++];
        }
    }
    cout << ans;
    return 0;
}