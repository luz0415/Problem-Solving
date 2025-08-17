#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int grid[25][25];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
vector<vector<bool>> visited;
vector<int> peoples;

void DFS(int x, int y)
{
    peoples[peoples.size()-1]++;

    for(int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        if(visited[nx][ny] || grid[nx][ny] == 0) continue;
        visited[nx][ny] = true;
        DFS(nx, ny);
    }
}

int main() {
    cin >> n;

    visited.assign(n, vector<bool>(n, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    // Please write your code here.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(visited[i][j] || grid[i][j] == 0) continue;
            peoples.push_back(0);
            visited[i][j] = true;
            DFS(i, j);
        }
    }

    sort(peoples.begin(), peoples.end());

    cout << peoples.size() << '\n';
    for(int i: peoples)
    {
        cout << i << '\n';
    }
    return 0;
}
