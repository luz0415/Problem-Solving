#include <iostream>
using namespace std;

int N, M;
int T[100000];


// 도착한 순서가 늦은 사람은 빨리 도착한 사람보다 레인 번호 늦어야 함
// 각 레인 별 수영장 이용시간의 총합중 최댓값의 최솟값

bool IsPossible(int maxLaneTime)
{
    int laneIdx = 0;
    int curLane = 0;
    for (int i = 0; i < N; i++)
    {
        if (T[i] > maxLaneTime) { return false; }

        if (curLane + T[i] <= maxLaneTime)
        {
            curLane += T[i];
        }
        else
        {
            laneIdx++; curLane = T[i];
        }
    }

    return laneIdx < M;
}

int BinarySearch()
{
    int L = 0, R = 1440*100000;
    int ans = 1440*100000;

    while (L <= R)
    {
        int mid = (L+R) / 2;

        if (IsPossible(mid))
        {
            R = mid - 1;
            ans = min(mid, ans);
        }
        else
        {
            L = mid + 1;
        }
    }
    return ans;
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        cin >> T[i];
    }

    cout << BinarySearch();
    return 0;
}