#include <iostream>
#include <unordered_map>
using namespace std;

int n, k;
int arr[100000];

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    unordered_map<int, int> um;

    int ans = 0;
    int L = 0;
    for (int i = 0; i < n; i++)
    {
        while (um[arr[i]] + 1 > k)
        {
            um[arr[L++]]--;
        }
        um[arr[i]]++;

        ans = max(ans, i-L+1);
    }

    cout << ans;
    return 0;
}
