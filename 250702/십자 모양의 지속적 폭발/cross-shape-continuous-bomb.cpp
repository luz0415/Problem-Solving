#include <iostream>

using namespace std;

int n, m;
int grid[200][200];
int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, 1, -1};

void Bomb(int r, int c)
{
    int radius = grid[r][c];

    for(int rad = 0; rad < radius; rad++)
    {
        for(int i = 0; i < 4; i++)
        {
            int nr = r + dr[i] * rad;
            int nc = c + dc[i] * rad;
            if(nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
            grid[nr][nc] = 0;
        }
    }

}

void Drop()
{
    for(int c = 0; c < n; c++)
    {
        int tmp[200] = {0, };
        int tmpIdx = 0;
        for(int r = n-1; r >= 0; r--)
        {
            if(grid[r][c] == 0) continue;
            tmp[tmpIdx++] = grid[r][c];
        }

        for(int r = n-1; r >= n-tmpIdx; r--)
        {
            grid[r][c] = tmp[n-1-r];
        }
        for(int r = n-tmpIdx-1; r >= 0; r--)
        {
            grid[r][c] = 0;
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        int c;
        cin >> c;
        c--;
        
        int topIdx = -1;
        for(int r = n-1; r >= 0; r--)
        {
            if(grid[r][c] != 0) topIdx = r;
        }
        if(topIdx == -1) continue;

        Bomb(topIdx, c);
        Drop();
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << grid[i][j] << ' ';
        }cout << '\n';
    }
    return 0;
}
