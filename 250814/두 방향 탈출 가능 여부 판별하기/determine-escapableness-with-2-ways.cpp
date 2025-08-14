#include <iostream>

using namespace std;

int n, m;
int grid[100][100];
bool visit[100][100];

bool can = false;
int dx[] = {1, 0};
int dy[] = {0, 1};

void DFS(int x, int y)
{
    if(x == n-1 && y == m-1)
    {
        can = true;
        return;
    }

    for(int i = 0; i < 2; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if(visit[nx][ny] || grid[nx][ny] == 0) continue;

        visit[nx][ny] = true;
        DFS(nx, ny);
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            visit[i][j] = false;
        }
    }

    // Please write your code here.
    DFS(0, 0);
    cout << can;
    return 0;
}
