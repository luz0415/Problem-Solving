#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

struct compare{
    bool operator()(pair<pair<int, int>, int> &a, pair<pair<int, int>, int>& b)
    {
        if(a.first.first == b.first.first) return a.first.second > b.first.second;
        return a.first.first > b.first.first;
    }
};
int n, m, t, k;
// 우선순위가 낮은 것이 top으로 오도록
// {{속도, 인덱스}, 방향} 속도가 낮은 것이 top으로, 속도가 같을때는 인덱스가 낮은것이 top으로
priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, compare> grid[50][50];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int main() {
    cin >> n >> m >> t >> k;

    for (int i = 0; i < m; i++) {
        int r, c, d, v;
        char dir;
        cin >> r >> c >> dir >> v;
        r--; c--;
        if(dir == 'U') d = 0;
        else if(dir == 'D') d = 1;
        else if(dir == 'L') d = 2;
        else d = 3;

        grid[r][c].push({{v, i}, d});
    }

    for(int i = 0; i < t; i++)
    {
        priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, compare> nextGrid[50][50];
        for(int x = 0; x < n; x++)
        {
            for(int y = 0; y < n; y++)
            {
                while(!grid[x][y].empty())
                {
                    pair<pair<int, int>, int> elem = grid[x][y].top();
                    grid[x][y].pop();

                    int velocity = elem.first.first;
                    int nextX = x, nextY = y;
                    for(int v = 0; v < velocity; v++)
                    {                    
                        int nx = nextX + dx[elem.second];
                        int ny = nextY + dy[elem.second];
                        if(nx < 0 || nx >= n || ny < 0 || ny >= n)
                        {
                            if(elem.second == 0 || elem.second == 2) elem.second++;
                            else elem.second--;
                            nx = nextX + dx[elem.second];
                            ny = nextY + dy[elem.second];
                        }

                        nextX = nx; nextY = ny;
                    }
                    nextGrid[nextX][nextY].push({{velocity, elem.first.second}, elem.second});
                }
            }
        }

        for(int x = 0; x < n; x++)
        {
            for(int y = 0; y < n; y++)
            {
                while(nextGrid[x][y].size() > k)
                {
                    nextGrid[x][y].pop();
                }

                grid[x][y] = nextGrid[x][y];
            }
        }
    }
    // Please write your code here.
    int ans = 0;        
    for(int x = 0; x < n; x++)
    {
        for(int y = 0; y < n; y++)
        {
            //cout << grid[x][y].size() << ' ';
            ans += grid[x][y].size();
        }
        //cout << '\n';
    }
    cout << ans;
    return 0;
}
