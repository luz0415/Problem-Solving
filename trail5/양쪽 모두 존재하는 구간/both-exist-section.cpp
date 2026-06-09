#include <iostream>
#include <unordered_map>
#include <climits>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    int arr[100000];
    
    unordered_map<int, int> counts;
    unordered_map<int, int> outCounts;

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        outCounts[arr[i]]++;
    }


    int ans = INT_MAX;
    int L = 0, R = 0;

    for (R = 0; R < N; R++)
    {
        counts[arr[R]]++;
        outCounts[arr[R]]--;
        if (outCounts[arr[R]] == 0)
        {
            outCounts.erase(arr[R]);
        }

        while (counts.size() >= M)
        {
            if (outCounts.size() >= M) { ans = min(R-L+1, ans); }
            counts[arr[L]]--;
            outCounts[arr[L]]++;
            if (counts[arr[L]] == 0)
            {
                counts.erase(arr[L]);
            }
            L++;
        }
    }

    if (ans == INT_MAX) cout << -1;
    else cout << ans;
    return 0;
}