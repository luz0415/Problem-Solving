#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
int grid[20][20];

// 상 하 좌 우 좌상 좌하 우상 우하
int dx[] = {-1, 1, 0, 0, -1, 1, -1, 1};
int dy[] = {0, 0, -1, 1, -1, -1, 1, 1};

int main() {
    cin >> n >> m;
    vector<pair<int, int>> numCoord(n*n+1, {0, 0});

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            numCoord[grid[i][j]] = {i, j};
        }
    }

    // Please write your code here.
    for(int turn = 0; turn < m; turn++)
    {
        for(int i = 1; i <= n*n; i++)
        {
            int x = numCoord[i].first;
            int y = numCoord[i].second;

            
            int maxAdj = 0;
            int maxNx, maxNy;
            for(int d = 0; d < 8; d++)
            {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

                if(maxAdj < grid[nx][ny])
                {
                    maxAdj = grid[nx][ny];
                    maxNx = nx; maxNy = ny;
                }
            }

            grid[maxNx][maxNy] = i;
            grid[x][y] = maxAdj;

            numCoord[i] = {maxNx, maxNy};
            numCoord[maxAdj] = {x, y};
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << grid[i][j] << ' ';
        }cout << endl;
    }

    return 0;
}
