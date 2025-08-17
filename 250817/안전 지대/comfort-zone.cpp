#include <iostream>
#include <vector>
using namespace std;

int N, M;
int grid[50][50];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int ans = 1, maxCount = 0, count = 0;
vector<vector<bool>> visited;

void DFS(int x, int y, int k)
{

    for(int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
        if(visited[nx][ny] || grid[nx][ny] <= k) continue;
        
        visited[nx][ny] = true;
        DFS(nx, ny, k);
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
        }
    }

    // Please write your code here.
    
    for(int k = 1; k < 100; k++)
    {
        visited.assign(N, vector<bool>(M, false));
        count = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if(grid[i][j] <= k || visited[i][j]) continue;
                visited[i][j] = true;
                count++;
                DFS(i, j, k);
            }
        }

        if(count > maxCount)
        {
            maxCount = count;
            ans = k;
        }
    }
    cout << ans << ' ' << maxCount;
    return 0;
}
