#include <iostream>

using namespace std;

int n, s;
int arr[100000];

int main() {
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // 투포인터로 전진시켜가면서, S이상이 되면 i 증가, 그리고 가장 짧은지 체크
    int ans = 100001;
    int sum = 0;
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        while (sum < s && j < n)
        {
            sum += arr[j++];
        }
        
        if (sum >= s) ans = min(ans, j-i);
        sum -= arr[i];
    }

    cout << ((ans == 100001) ? -1 : ans);

    return 0;
}
