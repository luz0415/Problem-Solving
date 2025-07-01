#include <iostream>

using namespace std;

int grid[4][4];
char dir;

void rotateGrid(char dir)
{
    int tmp[4][4] = {0,};
    if(dir == 'L')
    {
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                tmp[i][j] = grid[j][3-i];
            }
        }
    }
    else if(dir == 'R')
    {
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                tmp[i][j] = grid[3-j][i];
            }
        }
    }
    else if(dir == 'U')
    {
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                tmp[i][j] = grid[3-i][j];
            }
        }
    }
    else return;

    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            grid[i][j] = tmp[i][j];
        }
    }
}

int main() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> grid[i][j];
        }
    }

    cin >> dir;

    // Please write your code here.
    rotateGrid(dir);
    for(int j = 0; j < 4; j++)
    {
        int prev = -1;
        int prevIdx = -1;
        for(int i = 3; i >= 0; i--)
        {
            if(prev == grid[i][j])
            {
                prev = -1;
                grid[prevIdx][j] = 0;
                grid[i][j] *= 2;
            }
            else if(grid[i][j] != 0){
                prev = grid[i][j];
                prevIdx = i;
            }
        }
    }

    for(int j = 0; j < 4; j++)
    {
        int tmp[4] = {0, };
        int tmpIdx = 3;
        for(int i = 3; i >= 0; i--)
        {
            if(grid[i][j] != 0) tmp[tmpIdx--] = grid[i][j];
        }
        
        for(int i = 0; i < 4; i++)
        {
            grid[i][j] = tmp[i];
        }
    }

    if(dir == 'L') dir = 'R';
    else if(dir == 'R') dir = 'L';
    rotateGrid(dir);

    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            cout << grid[i][j] << ' ';
        }cout << '\n';
    }
    return 0;
}
