#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<vector<int>> city;
vector<pair<int, int>> houses;
vector<pair<int, int>> chickens;
vector<int> combinations;
int ans;

void Input()
{
    cin >> N >> M;
    city.assign(N, vector<int>(N));
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> city[i][j];
            if(city[i][j] == 1) houses.push_back({i, j});
            else if(city[i][j] == 2) chickens.push_back({i, j});
        }
    }
}

int Distance(int x1, int y1, int x2, int y2)
{
    return abs(x1 - x2) + abs(y1 - y2);
}

void DFS(int idx, int cnt, int end)
{
    if(cnt > 0) combinations[cnt-1] = idx;
    if(cnt == end)
    {
        int sum = 0;
        for(int i = 0; i < houses.size(); i++)
        {
            int minDist = INT_MAX;
            for(int j = 0; j < cnt; j++)
            {
                int chickenIdx = combinations[j];
                int dist = Distance(houses[i].first, houses[i].second, chickens[chickenIdx].first, chickens[chickenIdx].second);
                minDist = min(minDist, dist);
            }
            sum += minDist;
        }
        ans = min(ans, sum);
        return;
    }

    for(int i = idx+1; i < chickens.size(); i++)
    {
        DFS(i, cnt+1, end);
    }
}

void Solve()
{
    ans = INT_MAX;
    combinations.assign(M, 0);
    DFS(-1, 0, M);
    
    cout << ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();
    Solve();
}