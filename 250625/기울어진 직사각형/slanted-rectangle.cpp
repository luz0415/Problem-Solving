#include <iostream>

using namespace std;

int n;
int grid[20][20];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    // Please write your code here.
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i-1 < 0 || i+1 >= n || j-1 < 0 || j+1 >= n) { continue; }
            
            //우상
            int squareScore = grid[i-1][j] + grid[i+1][j] + grid[i][j-1] + grid[i][j+1];
            int nx = i-1; int ny = j+1;
            bool isCanUpRight = (nx - 1 >= 0) && (ny + 1 < n);
            while(isCanUpRight)
            {
                squareScore += grid[nx-1][ny] + grid[nx][ny+1];
                nx--; ny++;
                isCanUpRight = (nx - 1 >= 0) && (ny + 1 < n);
            }

            ans = ans < squareScore ? squareScore : ans;
            //좌상
            squareScore = grid[i-1][j] + grid[i+1][j] + grid[i][j-1] + grid[i][j+1];
            nx = i-1; ny = j-1;
            bool isCanUpLeft = (nx - 1 >= 0) && (ny - 1 >= n);
            while(isCanUpLeft)
            {
                squareScore += grid[nx-1][ny] + grid[nx][ny-1];
                nx--; ny--;
                isCanUpLeft = (nx - 1 >= 0) && (ny - 1 >= n);
            }

            ans = ans < squareScore ? squareScore : ans;
        }
    }
    cout << ans;
    return 0;
}
