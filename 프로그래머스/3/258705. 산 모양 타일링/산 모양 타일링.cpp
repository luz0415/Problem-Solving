#include <string>
#include <vector>
#include <stack>
#include <utility>
#include <iostream>

using namespace std;

vector<vector<int>> dp;
vector<bool> hasTop;
int triangleCount = 0;

int solution(int n, vector<int> tops) {
    int answer = 0;
    
    triangleCount += 2 * n + 1;
    
    dp.assign(triangleCount, vector<int>(2));
    hasTop.assign(triangleCount, false);
    for(int i = 0; i < n; i++)
    {
        if(tops[i] == 1)
        {
            hasTop[2*i+1] = true;
        }
    }
    
    dp[0][0] = 1;
    dp[0][1] = 0;
    for(int i = 0; i < triangleCount - 1; i++)
    {
        dp[i+1][0] += (dp[i][0] + dp[i][1]) % 10007;
        dp[i+1][1] += (dp[i][0]) % 10007;
        if(hasTop[i])
        {
            dp[i+1][0] += dp[i][0] % 10007;
        }
    }
    
    return (dp[triangleCount-1][0] + dp[triangleCount-1][1]) % 10007;
}