#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int n, m;
int grid[100][100];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};


bool BFS(int low, int high)
{
    queue<pair<int, int>> q;
    q.push({0, 0});

    bool visited[100][100] = {};
    visited[0][0] = true;

    if (grid[0][0] < low || grid[0][0] > high) { return false; }    
    
    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        if (x == n-1 && y == m-1) { return true; }

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) { continue; }
            if (visited[nx][ny]) { continue; }
            if (grid[nx][ny] < low || grid[nx][ny] > high) { continue; }
            
            visited[nx][ny] = true;
            q.push({nx, ny});
        }
    }

    return false;
}

bool IsPossible(int diff)
{
    for (int i = 1; i + diff <= 500; i++)
    {
        if(BFS(i, i+diff)) { return true; }
    }
    return false;
}

int BinarySearch()
{
    int L = 0, R = 500;
    int ans = 500;

    while (L <= R)
    {
        int mid = (L+R) / 2;

        if(IsPossible(mid))
        {
            R = mid - 1;
            ans = mid;
        }
        else
        {
            L = mid + 1;
        }
    }
    return ans;
}
int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    cout << BinarySearch();
    return 0;
}