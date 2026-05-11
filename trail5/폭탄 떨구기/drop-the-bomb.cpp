#include <iostream>
#include <algorithm>
using namespace std;

int N, K;
int x[50000];

bool CanBombAll(int R)
{
    int nowK = 1;
    int nowX = x[0];

    for (int i = 1; i < N; i++)
    {
        if (x[i] - nowX > 2*R)
        {
            nowX = x[i];
            nowK++;
        }
    }

    return nowK <= K;
}

int BinarySearch()
{
    int L = 0, R = 1e9;
    int ans = 1e9;

    while (L <= R)
    {
        int mid = (L+R) / 2;

        if (CanBombAll(mid))
        {
            R = mid-1;
            ans = mid;
        }
        else
        {
            L = mid+1;
        }
    }

    return ans;
}

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        cin >> x[i];
    }

    sort(x, x+N);
    cout << BinarySearch();
    return 0;
}