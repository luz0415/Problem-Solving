#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int n, m;
int grid[20][20];
vector<pair<int, int>> bomb;
int bombX[3][4] = {{-2, -1, 1, 2}, {-1, 1, 0, 0}, {-1, -1, 1, 1}};
int bombY[3][4] = {{0, 0, 0, 0}, {0, 0, -1, 1}, {-1, 1, -1, 1}};
int ans;

void Bomb(int bombIdx)
{
    if(bombIdx == m)
    {
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if(grid[i][j] == 1) count++;
            }
        }
        ans = ans < count ? count : ans;
        return;
    }

    int x = bomb[bombIdx].first;
    int y = bomb[bombIdx].second;
    for(int bombKind = 0; bombKind < 3; bombKind++)
    {
        vector<pair<int, int>> explosed;
        if(grid[x][y] == 0) 
        {
            explosed.push_back(bomb[bombIdx]);
            grid[x][y] = 1;
        }
        for(int d = 0; d < 4; d++)
        {
            int nx = x + bombX[bombKind][d];
            int ny = y + bombY[bombKind][d];

            if(nx < 0 || nx >= n || ny < 0 || ny >= n) {continue;}
            if(grid[nx][ny] == 1) {continue;}

            grid[nx][ny] = 1;
            explosed.push_back({nx, ny});
        }
        Bomb(bombIdx + 1);

        for(int explosedIdx = 0; explosedIdx < explosed.size(); explosedIdx++)
        {
            grid[explosed[explosedIdx].first][explosed[explosedIdx].second] = 0;
        }
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int num;
            cin >> num;
            if(num == 1) {bomb.push_back({i, j}); m++;}
        }
    }

    // Please write your code here.
    Bomb(0);
    cout << ans;
    return 0;
}
