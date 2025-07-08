#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> grid[20][20];
int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int num; cin >> num;
            grid[i][j].push_back(num);
        }
    }

    for (int i = 0; i < m; i++) {
        int num; cin >> num;

        int numX = -1, numY = -1, numZ = -1;
        for(int x = 0; x < n; x++)
        {
            for(int y = 0; y < n; y++)
            {
                for(int z = 0; z < grid[x][y].size(); z++)
                {
                    if(grid[x][y][z] == num)
                    {
                        numX = x; numY = y; numZ = z;
                        break;
                    }
                }
                if(numX != -1) break;
            }
            if(numX != -1) break;
        }

        int nextX = -1, nextY = -1;
        int nextBest = 0;
        for(int d = 0; d < 8; d++)
        {
            int adjX = dx[d] + numX;
            int adjY = dy[d] + numY;
            if(adjX < 0 || adjX >= n || adjY < 0 || adjY >= n) continue;
            
            for(int z = 0; z < grid[adjX][adjY].size(); z++)
            {
                if(grid[adjX][adjY][z] > nextBest)
                {
                    nextBest = grid[adjX][adjY][z];
                    nextX = adjX; nextY = adjY;
                }
            }
        }

        if(nextX == -1) continue;
        
        vector<int>& originVec = grid[numX][numY];
        vector<int>& destVec = grid[nextX][nextY];
        
        vector<int> moveVec(originVec.begin() + numZ, originVec.end());
        originVec = vector<int>(originVec.begin(), originVec.begin() + numZ);
        destVec.insert(destVec.end(), moveVec.begin(), moveVec.end());
    }

    for(int x = 0; x < n; x++)
    {
        for(int y = 0; y < n; y++)
        {
            if(grid[x][y].size() == 0) cout << "None";
            for(int z = grid[x][y].size()-1; z >= 0; z--)
            {
                cout << grid[x][y][z] << ' ';
            }
            cout << '\n';
        }
    }

    return 0;
}
