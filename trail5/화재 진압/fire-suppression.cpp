#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    int fire[100000], station[100000];
    for (int i = 0; i < N; i++)
    {
        cin >> fire[i];
    }
    for (int i = 0; i < M; i++)
    {
        cin >> station[i];
    }

    sort(fire, fire+N);
    sort(station, station+M);

    int ans = 0;
    int j = 0;
    for (int i = 0; i < N; i++)
    {
        // 현재 화재 위치에서 가장 가까운 소방서 체크
        int minDist = abs(fire[i] - station[j]);
        while (j+1 < M)
        {
            int nowDist = abs(fire[i] - station[j+1]);
            if (minDist > nowDist)
            {
                minDist = nowDist;
                j++;
            }
            else
            {
                break;
            }
        }

        ans = max(minDist, ans);
    }

    cout << ans;
    return 0;
}