#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int n, m;
int grid[20][20];

bool CheckPlusRect(int x1, int y1, int x2, int y2)
{
    for(int x = x1; x <= x2; x++)
    {
        for(int y = y1; y <= y2; y++)
        {
            if(grid[x][y] <= 0) return false;
        }
    }
    return true;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    // Please write your code here.
    int ans = -1;
    for(int x1 = 0; x1 < n; x1++)
    {
        for(int y1 = 0; y1 < m; y1++)
        {
            for(int x2 = x1; x2 < n; x2++)
            {
                for(int y2 = y1; y2 < m; y2++)
                {
                    if(CheckPlusRect(x1, y1, x2, y2))
                    {
                        int scale = (abs(x1-x2) + 1) * (abs(y1-y2) + 1);
                        ans = scale > ans ? scale : ans;
                    }
                }
            }
        }
    }

    cout << ans;
    return 0;
}
