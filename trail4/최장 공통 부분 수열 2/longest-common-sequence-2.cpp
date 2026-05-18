#include <iostream>
using namespace std;

// dp[i][j] = A[i], B[j]까지 고려했을 때 공통 부분 수열
int dp[1001][1001];
pair<int, int> path[1001][1001];

int main() {
    string A, B;
    cin >> A >> B;
    A = " " + A;
    B = " " + B;

    for (int i = 1; i < A.length(); i++)
    {
        for (int j = 1; j < B.length(); j++)
        {
            if (A[i] == B[j])
            {
                if (dp[i-1][j-1] + 1 > dp[i][j])
                {
                    dp[i][j] = dp[i-1][j-1] + 1;
                    path[i][j] = {i-1, j-1};
                }
            }
            else
            {
                if (dp[i-1][j] > dp[i][j])
                {
                    dp[i][j] = dp[i-1][j];
                    path[i][j] = {i-1, j};
                }
                if (dp[i][j-1] > dp[i][j])
                {
                    dp[i][j] = dp[i][j-1];
                    path[i][j] = {i, j-1};
                }
            }
        }
    }

    string ans = "";
    for (int i = A.length()-1, j = B.length()-1; i > 0 && j > 0;)
    {
        if (path[i][j] == make_pair(i-1, j-1) && A[i] == B[j])
        {
            ans = A[i] + ans;
            i--; j--;
        }
        else
        {
            pair<int, int> p = path[i][j];
            i = p.first;
            j = p.second;
        }
    }
    cout << ans;

    return 0;
}