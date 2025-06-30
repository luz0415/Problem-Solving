#include <iostream>

using namespace std;

int n;
int grid[200][200];
int r, c;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    cin >> r >> c;
    r--; c--;
    // Please write your code here.
    int bombScale = grid[r][c];
    for(int i = 0; i < bombScale; i++)
    {
        for(int d = 0; d < 4; d++)
        {
            int nx = r + dx[d] * i;
            int ny = c + dy[d] * i;
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            grid[nx][ny] = 0;
        }
    }

    for(int j = 0; j < n; j++)
    {
        int tmp[200] = {0, };
        int tmpIdx = n-1;
        for(int i = n-1; i >= 0; i--)
        {
            if(grid[i][j] == 0) continue;
            tmp[tmpIdx--] = grid[i][j];
        }

        for(int i = n-1; i >= 0; i--)
        {
            grid[i][j] = tmp[i];
        }
    }

    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << grid[i][j] << ' ';
        }cout << endl;
    }

    return 0;
}
