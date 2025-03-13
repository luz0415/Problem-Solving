#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> info, int n, int m) {
    int answer = -1;
    vector<vector<bool>> dp(n, vector<bool>(m, false));
    dp[0][0] = true;
    
    for(const vector<int>& nowInfo : info)
    {
        vector<vector<bool>> next(n, vector<bool>(m, false));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(dp[i][j])
                {
                    if(i+nowInfo[0] < n) next[i+nowInfo[0]][j] = true;
                    if(j+nowInfo[1] < m) next[i][j+nowInfo[1]] = true;
                }
            }
        }
        dp = next;
    }
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(dp[i][j])
            {
                if(answer == -1) answer = i;
                else answer = answer < i ? answer : i;
            }
        }
    }
    return answer;
}