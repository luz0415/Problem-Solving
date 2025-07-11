#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int n, m;
vector<pair<int, int>> lines;
bool lineGrid[12][16];
vector<int> originResult;
int ans;

vector<int> Ladder()
{
    vector<int> result(n+1);
    for(int i = 1; i <= n; i++)
    {
        int line = i;
        for(int stair = 1; stair <= 15; stair++)
        {
            if(lineGrid[line][stair])
            {
                line++;
            }
            else if(line > 1 && lineGrid[line-1][stair])
            {
                line--;
            }
        }
        result[i] = line;
    }

    return result;
}

void SelectLines(int step, int count)
{
    if(step == m)
    {
        vector<int> result = Ladder();
        for(int i = 1; i <= n; i++)
        {
            if(result[i] != originResult[i]) return;
        }

        ans = count < ans ? count : ans;
        return;
    }

    SelectLines(step+1, count);

    lineGrid[lines[step+1].first][lines[step+1].second] = true;
    SelectLines(step+1, count+1);
    lineGrid[lines[step+1].first][lines[step+1].second] = false;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        lines.push_back({a, b});
        lineGrid[a][b] = true;
    }

    // Please write your code here.
    originResult = Ladder();
    ans = m;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= 15; j++)
        {
            lineGrid[i][j] = false;
        }
    }
    SelectLines(-1, 0);
    cout << ans;
    return 0;
}
