#include <bits/stdc++.h>
using namespace std;

string s1, s2, s3;
int DP[101][101][101];

void Input()
{
    cin >> s1 >> s2 >> s3;
}

void Solve()
{
    for (int i = 0; i < s1.size(); i++)
    {
        for(int j = 0; j < s2.size(); j++)
        {
            for(int k = 0; k < s3.size(); k++)
            {
                if (s1[i] == s2[j] && s2[j] == s3[k])
                {
                    DP[i + 1][j + 1][k + 1] = max({DP[i + 1][j][k], DP[i][j + 1][k], DP[i][j][k + 1], DP[i + 1][j + 1][k], DP[i][j + 1][k + 1], DP[i + 1][j][k + 1], DP[i][j][k] + 1}); 
                }
                else
                {
                    DP[i + 1][j + 1][k + 1] = max({DP[i + 1][j][k], DP[i][j + 1][k], DP[i][j][k + 1], DP[i + 1][j + 1][k], DP[i][j + 1][k + 1], DP[i + 1][j][k + 1]}); 
                }
            }
        }
    }
    cout << DP[s1.size()][s2.size()][s3.size()];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();
    Solve();
}