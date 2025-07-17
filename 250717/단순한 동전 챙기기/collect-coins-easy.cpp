#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
using namespace std;

int N;
char grid[20][20];
vector<pair<int, pair<int, int>>> coins;
pair<int, int> s;
pair<int, int> e;

int dist;
int ans = -1;

int GetDistance(const pair<int, int>& a, const pair<int, int>& b)
{
    return abs(a.first - b.first) + abs(a.second - b.second);
}

void SelectCoin(int step, int idx)
{
    if(step == 3)
    {
        dist += GetDistance(coins[idx-1].second, e);
        if(ans == -1)
        {
            ans = dist;
        }
        else
        {
            ans = min(ans, dist);
        }
        return;
    }
    if(idx == coins.size()) return;

    pair<int, int> originCoord;
    if(idx > 0) originCoord = coins[idx-1].second;
    else originCoord = s;

    for(int i = idx; i < coins.size(); i++)
    {
        int d = GetDistance(originCoord, coins[i].second);
        dist += d;
        SelectCoin(step+1, i+1);
        dist -= d;
    }
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            cin >> grid[i][j];
            if(grid[i][j] == 'S')
            {
                s = {i, j};
            }
            else if(grid[i][j] == 'E')
            {
                e = {i, j};
            }
            else if(grid[i][j] != '.')
            {
                coins.push_back({grid[i][j]-'0', {i, j}});
            }
        }

    // Please write your code here.
    sort(coins.begin(), coins.end());
    SelectCoin(0, 0);
    cout << ans;
    return 0;
}
