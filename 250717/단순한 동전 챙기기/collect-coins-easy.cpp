#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
using namespace std;

int N;
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
        int d = GetDistance(coins[idx-1].second, e);
        dist += d;
        ans = ans == -1 ? dist : min(ans, dist);
        dist -= d;
        return;
    }
    if(idx == coins.size()) return;

    pair<int, int> originCoord;
    if(idx == 0) originCoord = s;
    else originCoord = coins[idx-1].second;

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
            char c;
            cin >> c;
            if(c == 'S')
            {
                s = {i, j};
            }
            else if(c == 'E')
            {
                e = {i, j};
            }
            else if(c != '.')
            {
                coins.push_back({c-'0', {i, j}});
            }
        }

    // Please write your code here.
    sort(coins.begin(), coins.end());
    SelectCoin(0, 0);
    cout << ans;
    return 0;
}
