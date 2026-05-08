#include <iostream>
#include <queue>
#include <utility>
#include <tuple>
using namespace std;

// 임의의 칸 여러개에 색칠했음
// 상하좌우 칸으로 이동이 가능
// D 이하로 차이나는 칸으로만 이동이 가능
// 색칠된 칸끼리는 꼭 이동해야할때, 가능한 D의 최솟값

int M, N;
int grid[100][100];
bool isColored[100][100];
int coloredCount;
pair<int, int> start;

int dx[] = {-1, 1, 0, 0};
int dy[] = { 0, 0, -1, 1};

bool BFS(int D)
{
    queue<pair<int, int>> q;
    q.push(start);

    bool visited[100][100] = {};
    visited[start.first][start.second] = true;

    int count = 0;
    while (!q.empty())
    {
        int x, y;
        tie(x, y) = q.front();
        q.pop();

        if (isColored[x][y])
        {
            count++;
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= M || ny < 0 || ny >= N) { continue; }
            if (visited[nx][ny]) { continue; }

            if (abs(grid[x][y] - grid[nx][ny]) <= D)
            {
                q.push({nx, ny});
                visited[nx][ny] = true;
            }
        }  
    }

    return count == coloredCount;
}

int BinarySearch()
{
    int L = 0, R = 1e9;
    int D = 1e9;

    while (L <= R)
    {
        int mid = (L+R) / 2;

        if (BFS(mid))
        {
            D = min(D, mid);
            R = mid-1;
        }
        else
        {
            L = mid + 1;
        }
    }
    return D;
}

int main() {
    cin >> M >> N;

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> isColored[i][j];
            if (isColored[i][j] == 1)
            {
                start = {i, j};
                coloredCount++;
            }
        }
    }

    cout << BinarySearch();
    return 0;
}