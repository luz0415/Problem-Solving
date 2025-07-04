#include <iostream>

using namespace std;

int N;
int x, y;
char grid[100][100];
int visit[100][100];

int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};

int main() {
    cin >> N;
    cin >> x >> y;
    x--; y--;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
            visit[i][j] = 0;
        }
    }

    // Please write your code here.
    int dir = 0;
    int time = 0;
    while(1)
    {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        
        // 1. 바로 나갈 수 있다면
        if(nx < 0 || nx >= N || ny < 0 || ny >= N) { time++; break; }
        
        if(visit[x][y] >= 2) { time = -1; break; }
        visit[x][y]++;

        // 2. 벽이라면
        if(grid[nx][ny] == '#')
        {
            dir = (dir+1) % 4;
            continue;
        }
        
        // 3. 이동 방향 기준 오른쪽에 벽이 있다면
        int rightDir = (dir+3) % 4;
        int rightX = nx + dx[rightDir];
        int rightY = ny + dy[rightDir];
        if(grid[rightX][rightY] == '#')
        {
            time++;
            x = nx; y = ny;
        }
        // 4. 벽이 없다면 이동 후 시계방향으로 틀어서 한칸 더 이동
        else
        {
            time += 2;
            x = rightX; y = rightY;
            dir = rightDir;
        }
    }

    cout << time;
    return 0;
}
