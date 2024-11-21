#include <bits/stdc++.h>
using namespace std;

const int minValue = -1000000;

// 하, 좌, 우
int dx[] = {1, 0, 0};
int dy[] = {0, -1, 1};
int DP[1000][1000][3];

int N, M;
vector<vector<int>> mars;
vector<vector<bool>> visited;

void Input()
{
    cin >> N >> M;
    mars.assign(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> mars[i][j];
        }
    }
}

bool IsInMars(int x, int y)
{
    return (x >= 0 && x < N && y >= 0 && y < M);
}

int DFS(int x, int y, int dir)
{
    if (x == N - 1 && y == M - 1)
    {
        return mars[x][y];
    }

    if(DP[x][y][dir] != minValue)
    {
        return DP[x][y][dir];
    }

    visited[x][y] = true;

    int maxCost = minValue;
    for(int i = 0; i < 3; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(IsInMars(nx, ny) == false) continue;

        if(visited[nx][ny]) continue;
        maxCost = max(maxCost, DFS(nx, ny, i));
    }
    DP[x][y][dir] = maxCost + mars[x][y];
    visited[x][y] = false;

    return DP[x][y][dir];
}

void Solve()
{
    visited.assign(N, vector<bool>(M, false));
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            DP[i][j][0] = DP[i][j][1] = DP[i][j][2] = minValue;
        }
    }
    cout << DFS(0, 0, 0);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();
    Solve();
}