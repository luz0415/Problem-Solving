#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<vector<int>> edges;
vector<bool> visited;
int ans;

void DFS(int v)
{
    ans++;
    for(int adj: edges[v])
    {
        if(visited[adj]) continue;
        visited[adj] = true;
        DFS(adj);
    }
}

int main() {
    cin >> n >> m;
    edges.assign(n, vector<int>());
    visited.assign(n, false);

    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        from--; to--;
        edges[from].push_back(to);
        edges[to].push_back(from);
    }

    // Please write your code here.
    visited[0] = true;
    DFS(0);
    cout << ans-1;
    return 0;
}
