#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 각 그룹의 수들끼리는 K를 초과한 차이가 나면 안됨
// 그룹이 두 개 일때 그룹에 속하는 수들은 최대 몇개?

int main() {
    int N, K; cin >> N >> K;

    vector<int> arr(N);
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    // 일단 sort해
    sort(arr.begin(), arr.end());

    // R이 마지막인 가장 긴 그룹
    int bestR[50000] = {};
    // L이 시작인 가장 긴 그룹
    int bestL[50000] = {};
    int L = 0, R = 0;

    for (R = 0; R < N; R++)
    {
        // 그룹이 불가능한 상황
        while (arr[R] - arr[L] > K)
        {
            L++;
        }

        bestR[R] = max(bestR[R], R-L+1);
        bestL[L] = max(bestL[L], R-L+1);
    }

    int until[50000] = {};
    until[0] = 1;
    for (int i = 1; i < N; i++)
    {
        until[i] = max(until[i-1], bestR[i]);
    }
    
    int from[50000] = {};
    from[N-1] = 1;
    for (int i = N-2; i >= 0; i--)
    {
        from[i] = max(from[i+1], bestL[i+1]);
    }

    int ans = 0;
    // i일때 i를 기준으로 0~i까지 생기는 가장 큰 그룹수 + i+1~N-1까지 생기는 가장 큰 그룹수
    for (int i = 0; i < N; i++)
    {
        ans = max(ans, until[i] + from[i]);
    }
    cout << ans;
    return 0;
}