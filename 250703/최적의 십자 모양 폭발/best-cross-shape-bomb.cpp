#include <iostream>
using namespace std;
constexpr int MAX = 50;

int N;
int originalGrid[MAX][MAX];
int grid[MAX][MAX];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void ResetGrid()
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            grid[i][j] = originalGrid[i][j];
        }
    }
}

void Bomb(int x, int y)
{
    int bombSize = grid[x][y];

    for(int size = 0; size < bombSize; size++)
    {
        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i] * size;
            int ny = y + dy[i] * size;

            if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

            grid[nx][ny] = 0;
        }
    }

    for(int j = 0; j < N; j++)
    {
        int tmp[MAX] = {0,};
        int tmpIdx = N-1;
        for(int i = N-1; i >= 0; i--)
        {
            if(grid[i][j]) tmp[tmpIdx--] = grid[i][j];
        }

        for(int i = N-1; i >= 0; i--)
        {
            grid[i][j] = tmp[i];
        }
    }
}

int GetPairNum()
{
    int count = 0;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(grid[i][j] == 0) continue;
            for(int d = 0; d < 4; d++)
            {
                int nx = i + dx[d];
                int ny = j + dy[d];

                if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                if(grid[i][j] == grid[nx][ny]) count++;
            }
        }
    }

    return count;
}

int main() {
    cin >> N;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> originalGrid[i][j];

    int ans = 0;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            ResetGrid();
            Bomb(i, j);
            int pairNum = GetPairNum() / 2;
            ans = ans < pairNum ? pairNum : ans;
        }
    }
        
    cout << ans;
    return 0;
}