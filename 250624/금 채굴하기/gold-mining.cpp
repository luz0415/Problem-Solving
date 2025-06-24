#include <iostream>
#include <vector>
#include <stack>
#include <utility>
using namespace std;

int n, m;
int grid[20][20];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int mine(int k, int i, int j)
{
    int cost = k*k + (k+1) * (k+1);
    int goldCount = 0;

    vector<vector<bool>> visited(n, vector<bool>(n, false)); 
    stack<vector<int>> st;
    vector<int> v = {i, j, k};
    st.push(v);
    while(!st.empty())
    {
        vector<int> now = st.top();
        int x = now[0], y = now[1], nowK = now[2];
        st.pop();

        if(visited[x][y]) continue;
        visited[x][y] = true;

        goldCount += grid[x][y];
        if(nowK == 0) continue;

        for(int i = 0; i < 4; i++)
        {
            int nx = dx[i] + x;
            int ny = dy[i] + y;

            if(nx >= 0 && nx < n && ny >= 0 && ny < n)
            {
                vector<int> next = {nx, ny, nowK - 1};
                st.push(next);
            }
        }
    }

    if(cost <= goldCount * m)
    {
        return goldCount;
    }
    return -1;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    // Please write your code here.
    int ans = 0;
    for(int k = 0; k <= 10; k++)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                int gold = mine(k, i, j);
                ans = ans < gold ? gold : ans;
            }
        }
    }
    cout << ans;
    return 0;
}
