#include <iostream>
#include <algorithm>
using namespace std;

int n;
int grid[100][100];
int r, c, m1, m2, m3, m4, dir;
int dr[2][4] = {{-1, -1, 1, 1}, {-1, -1, 1, 1}};
int dc[2][4] = {{1, -1, -1, 1}, {-1, 1, 1, -1}};

int main() {
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> grid[i][j];

    cin >> r >> c >> m1 >> m2 >> m3 >> m4 >> dir;
    r--; c--;
    // Please write your code here.
    //반시계 구현

    if(dir == 1)
    {
        swap(m1, m4);
        swap(m2, m3);
    }
    r += m1*dr[dir][0]; c += m1*dc[dir][0];
    int tmp = grid[r][c];
    for(int m = 0; m < m1; m++)
    {
        int nr = r - m * dr[dir][0];
        int nc = c - m * dc[dir][0];

        grid[nr][nc] = grid[nr - dr[dir][0]][nc - dc[dir][0]];
    }
    r += m2*dr[dir][1]; c+= m2*dc[dir][1];
    int tmp2 = grid[r][c];
    for(int m = 0; m < m2; m++)
    {
        int nr = r - m * dr[dir][1];
        int nc = c - m * dc[dir][1];

        grid[nr][nc] = grid[nr - dr[dir][1]][nc - dc[dir][1]];
    }
    grid[r - dr[dir][1] * (m2-1)][c - dc[dir][1] * (m2-1)] = tmp;

    r += m3*dr[dir][2]; c+= m3*dc[dir][2];
    int tmp3 = grid[r][c];
    for(int m = 0; m < m3; m++)
    {
        int nr = r - m * dr[dir][2];
        int nc = c - m * dc[dir][2];

        grid[nr][nc] = grid[nr - dr[dir][2]][nc - dc[dir][2]];
    }
    grid[r - dr[dir][2] * (m3-1)][c - dc[dir][2] * (m3-1)] = tmp2;

    r += m4*dr[dir][3]; c+= m4*dc[dir][3];
    int tmp4 = grid[r][c];
    for(int m = 0; m < m4; m++)
    {
        int nr = r - m * dr[dir][3];
        int nc = c - m * dc[dir][3];

        grid[nr][nc] = grid[nr - dr[dir][3]][nc - dc[dir][3]];
    }
    grid[r - dr[dir][3] * (m4-1)][c - dc[dir][3] * (m4-1)] = tmp3;


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++) cout << grid[i][j] << " ";
        cout << '\n';
    }
    return 0;
}
