#include <iostream>
#include <algorithm>
using namespace std;

int n, m, t;
int a[20][20];
int beadCount[20][20];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int main() {
    cin >> n >> m >> t;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    int r, c;
    for (int i = 0; i < m; i++) {
        cin >> r >> c;
        r--; c--;
        beadCount[r][c] = 1;
    }

    // Please write your code here.
    for(int i = 0; i < t; i++)
    {
        int nextCount[20][20] = {0, };
        for(int nowX = 0; nowX < n; nowX++)
        {
            for(int nowY = 0; nowY < n; nowY++)
            {
                if(beadCount[nowX][nowY] == 0) continue;

                int highAdj = 0;
                int highNx, highNy;
                for(int d = 0; d < 4; d++)
                {
                    int nx = nowX + dx[d];
                    int ny = nowY + dy[d];

                    if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

                    if(highAdj < a[nx][ny])
                    {
                        highAdj = a[nx][ny];
                        highNx = nx; highNy = ny;
                    }
                }

                nextCount[highNx][highNy]++;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                beadCount[i][j] = nextCount[i][j];
                if(beadCount[i][j] > 1) beadCount[i][j] = 0;
            }
        } 
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans += beadCount[i][j];
        }
    } 
    cout << ans;
    return 0;
}
