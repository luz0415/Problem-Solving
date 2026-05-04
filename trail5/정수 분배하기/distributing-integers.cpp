#include <iostream>
using namespace std;

int arr[10000];
int N, M;

int BinarySearch()
{
    int L = 1, R = 100000;
    int K = 0;
    while (L <= R)
    {
        int mid = (L+R) / 2;

        int nowM = 0;
        for (int i = 0; i < N; i++)
        {
            nowM += arr[i] / mid;
        }

        if (nowM >= M)
        {
            L = mid + 1;
            K = max(mid, K);
        }
        else
        {
            R = mid - 1;
        }
    }
    return K;
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    cout << BinarySearch();
    return 0;
}