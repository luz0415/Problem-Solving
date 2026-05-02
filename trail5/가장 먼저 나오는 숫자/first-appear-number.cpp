#include <iostream>
using namespace std;

int N, M;
int arr[100000];

int LowerBound(int find)
{
    int L = 0, R = N-1;
    int idx = N;

    while (L <= R)
    {
        int mid = (L+R) / 2;

        if (arr[mid] >= find)
        {
            R = mid - 1;
            if (arr[mid] == find)
            {
                idx = min(idx, mid);
            }
        }
        else
        {
            L = mid + 1;
        }
    }

    return idx;
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < M; i++)
    {
        int x; cin >> x;
        int lb = LowerBound(x);
        if (lb == N) { cout << -1; }
        else { cout << lb+1; }
        cout << '\n';
    }
    return 0;
}