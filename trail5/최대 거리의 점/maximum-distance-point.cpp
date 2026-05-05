#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int arr[200000];

int BinarySearch()
{
    int L = 0, R = 1e9;
    int ans = 0;

    while (L <= R)
    {
        int mid = (L + R) / 2;

        int count = 1;
        int now = arr[0];
        for (int i = 1; i < N; i++)
        {
            if (arr[i] - now >= mid)
            {
                count++;
                now = arr[i];
            }
        }

        if (count >= M)
        {
            L = mid + 1;
            ans = max(ans, mid);
        }
        else
        {
            R = mid - 1;
        }
    }
    return ans;
}


int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr+N);

    cout << BinarySearch();
    return 0;
}