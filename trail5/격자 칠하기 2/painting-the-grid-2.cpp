#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int N; 
int threshold;
int grid[100][100];
bool visited[100][100];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int BFS(int sx, int sy, int D)
{
    int count = 0;
    queue<pair<int, int>> q;
    q.push({sx, sy});
    visited[sx][sy] = true;

    while(!q.empty())
    {
        count++;
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = dx[i] + x;
            int ny = dy[i] + y;

            if (nx < 0 || nx >= N || ny < 0 || ny >= N) { continue; }
            if (visited[nx][ny]) { continue; }
            if (abs(grid[x][y] - grid[nx][ny]) > D) { continue; }

            q.push({nx, ny});
            visited[nx][ny] = true;
        }
    }

    return count;
}

int BinarySearch()
{
    int L = 0, R = 1e6;
    int ans = 1e6;

    while (L <= R)
    {
        int mid = (L+R) / 2;

        int colored = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (visited[i][j]) { continue; }
                colored = max(colored, BFS(i, j, mid));
            }
        }

        if (colored >= threshold)
        {
            ans = min(mid, ans);
            R = mid - 1;
        }
        else
        {
            L = mid + 1;
        }

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                visited[i][j] = false;
            }
        }
    }

    return ans;
}

int main() {
    cin >> N;
    threshold = (N*N) / 2 + N%2;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> grid[i][j];
        }
    }

    cout << BinarySearch();
    return 0;
}