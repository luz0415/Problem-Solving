#include <bits/stdc++.h>
using namespace std;

int N, K;
vector<vector<int>> T;
vector<bool> visited;
int ans = INT_MAX;

void Input()
{
    cin >> N >> K;
    T.assign(N, vector<int>(N));
    for (int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> T[i][j];
        }
    }
}

void DFS(int now, int time, int depth)
{
    if(depth == N)
    {
        ans = min(ans, time);
        return;
    }

    for(int i = 0; i < N; i++)
    {
        if(visited[i]) continue;
        visited[i] = true;
        DFS(i, time + T[now][i], depth + 1);
        visited[i] = false;
    }
}

void Solve()
{
    for(int k = 0; k < N; k++)
    {
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                T[i][j] = min(T[i][j], T[i][k] + T[k][j]);
            }
        }
    }
    
    visited.assign(N, false);
    visited[K] = true;

    DFS(K, 0, 1);
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