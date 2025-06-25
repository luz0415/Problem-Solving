#include <iostream>
#include <algorithm>
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
            if(i-2 < 0 || j+1 >= n || j-1  < 0) { continue; }
            int maxRightNum = min(n-j-1, i-1);
            for(int rightNum = 1; rightNum <= maxRightNum; rightNum++)
            {
                int leftNum = min(j, min(j+rightNum - 1, i-rightNum));
                int squareScore = 0;
                int nx = i, ny = j;
                for(int num = 1; num <= rightNum; num++)
                {
                    nx--; ny++;
                    squareScore += grid[nx][ny];
                }
                for(int num = 1; num <= leftNum; num++)
                {
                    nx--; ny--;
                    squareScore += grid[nx][ny];
                }
                for(int num = 1; num <= rightNum; num++)
                {
                    nx++; ny--;
                    squareScore += grid[nx][ny];
                }
                for(int num = 1; num <= leftNum; num++)
                {
                    nx++; ny++;
                    squareScore += grid[nx][ny];
                }
                ans = squareScore > ans ? squareScore : ans;
            }
        }
    }
    cout << ans;
    return 0;
}
