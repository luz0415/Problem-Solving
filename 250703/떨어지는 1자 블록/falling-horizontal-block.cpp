#include <iostream>

using namespace std;

int n, m, k;
int grid[100][100];

int main() {
    cin >> n >> m >> k;
    k--;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    // Please write your code here.
    int r = 0;
    bool isContinue = true;
    while(isContinue)
    {
        r++;
        if(r < n) isContinue = true;
        else
        {
            r--; break;
        }
        for(int c = k; c < k+m; c++)
        {
            if(grid[r][c])
            {
                r--;
                isContinue = false;
                break;
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(i == r && j >= k && j < k+m) cout << 1 << ' ';
            else cout << grid[i][j] << ' ';
        }cout << '\n';
    }

    return 0;
}
