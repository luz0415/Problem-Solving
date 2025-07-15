#include <iostream>

using namespace std;

int n;
int num[4][4];
int move_dir[4][4];
int r, c;
int dx[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };

int count = 0;
int ans = 0;

void Jump(int x, int y)
{
    int dir = move_dir[x][y];
    int nx = x + dx[dir];
    int ny = y + dy[dir];

    while(nx >= 0 && nx < n && ny >= 0 && ny < n)
    {
        if(num[x][y] < num[nx][ny])
        {
            count++;
            Jump(nx, ny);
            count--;
        }
        nx += dx[dir];
        ny += dy[dir];
    }

    ans = count > ans ? count : ans;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> num[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) { cin >> move_dir[i][j]; move_dir[i][j]--; }

    cin >> r >> c;
    r--; c--;

    // Please write your code here.
    Jump(r, c);
    cout << ans;
    return 0;
}
