#include <iostream>
using namespace std;

int N;
int grid[100][100];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int game(int x, int y, int dir)
{
    int count = 0;

    while(1)
    {
        count++;
        if(x < 0 || x >= N || y < 0 || y >= N) { break; }

        if(grid[x][y] == 1)
        {
            if(dir == 0) dir = 3;
            else if(dir == 1) dir = 2;
            else if(dir == 2) dir = 1;
            else dir = 0;
        }
        else if(grid[x][y] == 2)
        {
            if(dir == 0) dir = 2;
            else if(dir == 1) dir = 3;
            else if(dir == 2) dir = 0;
            else dir = 1;
        }

        x += dx[dir];
        y += dy[dir];
    }

    return count;
}

int main() {
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> grid[i][j];
        }
    }

    int ans = 0;
    for(int i = 0; i < N; i++)
    {
        int result = game(0, i, 1);
        ans = ans < result ? result : ans;
        
        result = game(i, 0, 3);
        ans = ans < result ? result : ans;
        
        result = game(i, N-1, 2);
        ans = ans < result ? result : ans;
        
        result = game(N-1, i, 0);
        ans = ans < result ? result : ans;
    }

    cout << ans;
    return 0;
}