#include <iostream>
#include <algorithm>
using namespace std;

int N, M, C;
int t[100000];

// N명을 M개의 버스에 태워야함
// 버스는 C명까지 태움
// 각 사람은 t[i]에 버스정류장 도착
// 버스가 출발할 때 까지 가장 오래기다려야하는 사람이 기다리는 시간의 최솟값

bool IsPossible(int waitTime)
{
    int nowTime = t[0];
    int nowBus = 1;
    int nowPeople = 0;

    for (int i = 0; i < N; i++)
    {
        if (nowTime + waitTime >= t[i] && nowPeople < C)
        {
            nowPeople++;
        }
        // 기다리는 시간 오버 or 버스에 사람 초과
        else
        {
            nowTime = t[i];
            nowPeople = 1;
            nowBus++;
        }
    }
    return nowBus <= M;
}

int BinarySearch()
{
    int L = 0, R = 1e9;
    int ans = 1e9;

    while (L <= R)
    {
        int mid = (L+R)/2;

        if (IsPossible(mid))
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
    cin >> N >> M >> C;

    for (int i = 0; i < N; i++)
    {
        cin >> t[i];
    }
    sort(t, t+N);

    cout << BinarySearch();
    return 0;
}