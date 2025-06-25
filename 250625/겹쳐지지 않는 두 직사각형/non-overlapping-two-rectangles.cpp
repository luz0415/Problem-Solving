#include <iostream>

using namespace std;

int n, m;
int grid[5][5];

int GetArea(int x1, int y1, int x2, int y2)
{
    int area = 0;
    for(int x = x1; x <= x2; x++)
    {
        for(int y = y1; y <= y2; y++)
        {
            area += grid[x][y];
        }
    }
    return area;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    // Please write your code here.
    int ans = -50000;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            int square1 = -25000;
            for(int x1 = 0; x1 <= i; x1++)
            {
                for(int y1 = 0; y1 <= j; y1++)
                {
                    int area = GetArea(x1, y1, i, j);
                    square1 = square1 < area ? area : square1;
                }
            }

            int square2 = -25000;
            for(int x1 = i+1; x1 < n; x1++)
            {
                for(int y1 = 0; y1 < m; y1++)
                {
                    for(int x2 = x1; x2 < n; x2++)
                    {
                        for(int y2 = y1; y2 < m; y2++)
                        {
                            int area = GetArea(x1, y1, x2, y2);
                            square2 = square2 < area ? area : square2;
                        }
                    }
                }
            }
            
            for(int x1 = 0; x1 < n; x1++)
            {
                for(int y1 = j+1; y1 < m; y1++)
                {
                    for(int x2 = x1; x2 < n; x2++)
                    {
                        for(int y2 = y1; y2 < m; y2++)
                        {
                            int area = GetArea(x1, y1, x2, y2);
                            square2 = square2 < area ? area : square2;
                        }
                    }
                }
            }

            ans = (square1 + square2) > ans ? (square1 + square2) : ans;
        }
    }
    
    cout << ans;
    return 0;
}
