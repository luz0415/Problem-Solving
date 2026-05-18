#include <iostream>
using namespace std;

int main() {
    int N; cin >> N;

    int arr[100000] = {};
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    int count[100001] = {};
    int j = 0;
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        while (j < N && count[arr[j]] == 0)
        {
            count[arr[j++]]++;
        }

        ans = max(ans, j - i);
        count[arr[i]]--;
    }

    cout << ans;
    return 0;
}