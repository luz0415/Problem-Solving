#include <iostream>

using namespace std;

int n, m;
int grid[200][200];

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    // Please write your code here.
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            int sum = 0;
            // ㅁ
            // ㅁ ㅁ
            if(i - 1 >= 0 && j + 1 < m)
            {
                sum = grid[i][j] + grid[i-1][j] + grid[i][j+1];
            }
            ans = ans < sum ? sum : ans;

            sum = 0;
            // ㅁ ㅁ
            // ㅁ
            if(i + 1 < n && j + 1 < m)
            {
                sum = grid[i][j] + grid[i+1][j] + grid[i][j+1];
            }
            ans = ans < sum ? sum : ans;

            sum = 0;
            // ㅁ ㅁ   
            //   ㅁ
            if(i + 1 < n && j - 1 >= 0)
            {
                sum = grid[i][j] + grid[i+1][j] + grid[i][j-1];
            }
            ans = ans < sum ? sum : ans;
            
            sum = 0;
            //    ㅁ
            // ㅁ ㅁ
            if(i - 1 >= 0 && j - 1 >= 0)
            {
                sum = grid[i][j] + grid[i-1][j] + grid[i][j-1];
            }
            ans = ans < sum ? sum : ans;
            
            sum = 0;
            // ㅁ ㅁ ㅁ
            if(j + 2 < m)
            {
                sum = grid[i][j] + grid[i][j+1] + grid[i][j+2];
            }
            ans = ans < sum ? sum : ans;

            sum = 0;
            // ㅁ
            // ㅁ
            // ㅁ
            if(i + 2 < n)
            {
                sum = grid[i][j] + grid[i+1][j] + grid[i+2][j];
            }
            ans = ans < sum ? sum : ans;
        }
    }
    cout << ans;
    return 0;
}
