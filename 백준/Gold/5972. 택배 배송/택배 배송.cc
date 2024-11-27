#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<vector<pair<int, int>>> paths;

void Input()
{
    cin >> N >> M;
    paths.assign(N, vector<pair<int, int>>());

    for(int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        paths[a].push_back({b, c});
        paths[b].push_back({a, c});
    }
}

void Solve()
{
    vector<int> dist(N, INT_MAX);
    vector<bool> visited(N, false);

    priority_queue<pair<int, int>, vector<pair<int, int>>> pq;
    pq.push({0, 0});
    dist[0] = 0;
    while(!pq.empty())
    {
        int now = pq.top().second;
        pq.pop();
        if(visited[now]) continue;
        visited[now] = true;
        
        for(int i = 0; i < paths[now].size(); i++)
        {
            int next = paths[now][i].first;
            int nextDist = paths[now][i].second;
            if(dist[next] > dist[now] + nextDist)
            {
                dist[next] = dist[now] + nextDist;
                pq.push({-dist[next], next});
            }
        }
    }

    cout << dist[N-1];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();
    Solve();
}