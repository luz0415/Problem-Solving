#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int N, M, K;
int x[10000], y[10000];
char d[1000];
int p[1000];
// 그냥 바닥 = 0, 사과 = -1, 헤드부터 1 ~
int grid[100][100];

int main() {
    cin >> N >> M >> K;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            grid[i][j] = 0;
        }
    }

    for (int i = 0; i < M; i++) 
    {
        cin >> x[i] >> y[i];
        x[i]--; y[i]--;
        grid[x[i]][y[i]] = -1;
    }

    vector<pair<int, int>> snake;

    int nowX = 0, nowY = 0;
    snake.push_back({nowX, nowY});
    grid[nowX][nowY] = 1;
    int time = 0;

    for (int i = 0; i < K; i++)
    {
        cin >> d[i] >> p[i];
        int dx, dy;
        
        if(d[i] == 'U'){
            dx = -1; dy = 0;
        }else if(d[i] == 'D'){
            dx = 1; dy = 0;
        }else if(d[i] == 'L'){
            dx = 0; dy = -1;
        }else{
            dx = 0; dy = 1;
        }

        for(int j = 0; j < p[i]; j++)
        {
            time++;
            int nx = nowX + dx;
            int ny = nowY + dy;

            if(nx < 0 || nx >= N || ny < 0 || ny >= N)
            {
                cout << time;
                return 0;
            }
                        
            if(grid[nx][ny] == -1)
            {
                pair<int, int> tail = snake[snake.size()-1];
                snake.push_back(tail);
            }
            
            for(int k = snake.size()-1; k > 0; k--)
            {
                grid[snake[k].first][snake[k].second] = 0;
                snake[k] = snake[k-1];
            }
            for(int k = snake.size()-1; k > 0; k--)
            {
                grid[snake[k].first][snake[k].second] = 1;
            }
            
            if(grid[nx][ny] == 1)
            {
                cout << time;
                return 0;
            }
            grid[nx][ny] = 1;
            snake[0] = {nx, ny};

            nowX = nx; nowY = ny;
        }  
    } 

    cout << time;
    return 0;
}
