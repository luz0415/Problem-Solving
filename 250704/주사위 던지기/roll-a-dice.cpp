#include <iostream>

using namespace std;

int n, m;
int r, c;
int directions[10000];
int grid[100][100];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int main() {
    cin >> n >> m >> r >> c;
    r--; c--;
    for (int i = 0; i < m; i++) {
        char dir;
        cin >> dir;
        if(dir == 'U'){
            directions[i] = 0;
        }else if(dir == 'D'){
            directions[i] = 1;
        }else if(dir == 'L'){
            directions[i] = 2;
        }else if(dir == 'R'){
            directions[i] = 3;
        }
    }

    grid[r][c] = 6;
    int currentDice = 6;
    // 상하좌우
    int adj[] = {5, 2, 4, 3};
    for(int i = 0; i < m; i++)
    {
        int dir = directions[i];
        int nr = r + dx[dir];    
        int nc = c + dy[dir];    

        if(nr < 0 || nr >= n || nc < 0 || nc >= n) { continue; }

        int nextDice = adj[dir];
        if(dir == 0){
            adj[0] = 7-currentDice;
            adj[1] = currentDice;
        }else if(dir == 1){
            adj[0] = currentDice;
            adj[1] = 7-currentDice;
        }else if(dir == 2){
            adj[2] = 7-currentDice;
            adj[3] = currentDice;
        }else if(dir == 3){
            adj[2] = currentDice;
            adj[3] = 7-currentDice;
        }
        currentDice = nextDice;
        grid[nr][nc] = currentDice;
        r = nr; c = nc;
    }

    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            ans += grid[i][j];
        }
    }

    cout << ans;
    return 0;
}
