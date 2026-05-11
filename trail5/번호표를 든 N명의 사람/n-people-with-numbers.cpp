#include <iostream>
#include <queue>
using namespace std;

int N, T;
int d[10000];

bool CanStage(int K)
{
    int nowTime = 0;
    int idx = K;

    priority_queue<int> pq;

    for (int i = 0; i < K; i++)
    {
       pq.push(-d[i]);
    }

    while (!pq.empty())
    {
        nowTime = -pq.top();
        pq.pop();

        if (idx < N)
        {
            pq.push(-(d[idx++] + nowTime));
        }
    }

    return nowTime <= T;
}

int BinarySearch()
{
    int L = 1, R = N;
    int ans = N;

    while (L <= R)
    {
        int mid = (L+R) / 2;

        if (CanStage(mid))
        {
            R = mid - 1;
            ans = mid;
        }
        else
        {
            L = mid + 1;
        }
    }

    return ans;
}

int main() {
    cin >> N >> T;

    for (int i = 0; i < N; i++)
    {
        cin >> d[i];
    }

    cout << BinarySearch();
    return 0;
}