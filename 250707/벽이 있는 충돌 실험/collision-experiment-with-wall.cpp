#include <iostream>

using namespace std;

int T;
int N, M;
int grid[50][50];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int main() {
    cin >> T;

    for (int t = 0; t < T; t++) {
        cin >> N >> M;

        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                grid[i][j] = -1;
            }
        }

        for (int i = 0; i < M; i++) {
            int x, y, d;
            char dir;
            cin >> x >> y >> dir;
            x--; y--;
            if(dir == 'U') d = 0;
            if(dir == 'D') d = 1;
            if(dir == 'L') d = 2;
            if(dir == 'R') d = 3;

            grid[x][y] = d;
        }

        for(int time = 0; time < 2*N; time++)
        {
            int nextGrid[50][50];
            for(int i = 0; i < N; i++)
            {
                for(int j = 0; j < N; j++)
                {
                    nextGrid[i][j] = -1;
                }
            }

            for(int i = 0; i < N; i++)
            {
                for(int j = 0; j < N; j++)
                {
                    if(grid[i][j] < 0) continue;
                    
                    int dir = grid[i][j];
                    int nx = i + dx[dir];
                    int ny = j + dx[dir];
                    int nDir = dir;

                    if(nx < 0 || nx >= N || ny < 0 || ny >= N)
                    {
                        nx = i; ny = j;
                        if(dir == 0 || dir == 2) nDir = dir + 1;
                        else nDir = dir - 1;
                    }

                    if(nextGrid[nx][ny] == -1) nextGrid[nx][ny] = nDir;
                    else nextGrid[nx][ny] = -2;
                }
            }

            for(int i = 0; i < N; i++)
            {
                for(int j = 0; j < N; j++)
                {
                    if(nextGrid[i][j] == -2) grid[i][j] = -1;
                    else grid[i][j] = nextGrid[i][j];
                }
            }
        }

        int ans = 0;
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                if(grid[i][j] >= 0) ans++;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
