#include <iostream>
#include <cmath>
using namespace std;

int n, m, r, c;
int grid[100][100] = {0, };
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main() {
    cin >> n >> m >> r >> c;
    r--; c--;
    // Please write your code here.
    grid[r][c] = 1;
    for(int t = 1; t <= m; t++)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 1)
                {
                    for(int d = 0; d < 4; d++)
                    {
                        int nx = i + dx[d] * pow(2, t-1);
                        int ny = j + dy[d] * pow(2, t-1);
                        if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

                        if(grid[nx][ny] == 0) grid[nx][ny] = 2;
                    }
                }
            }
        }

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 2)
                {
                    grid[i][j] = 1;
                }
            }
        }
    }
    
    int count = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            //cout << grid[i][j] << ' ';
            if(grid[i][j] != 0) count++;
        }//cout << endl;
    }

    cout << count;
    return 0;
}
