#include <string>
using namespace std;

int dx[] = {1, 0, 0, -1};
int dy[] = {0, -1, 1, 0};
string cmd[] = {"d", "l", "r", "u"};

string solution(int n, int m, int x, int y, int r, int c, int k) {
    x--; y--; r--; c--;
    
    int dist = abs(x - r) + abs(y - c);
    if(dist > k || (k - dist) % 2 == 1)
    {
        return "impossible";
    }
    
    int nowX = x;
    int nowY = y;
    string nowCmd = "";
    
    while(k > 0)
    {        
        for(int i = 0; i < 4; i++)
        {
            int nx = dx[i] + nowX;
            int ny = dy[i] + nowY;
            if(!(nx >= 0 && nx < n && ny >= 0 && ny < m)) { continue; }
            
            dist = abs(nx - r) + abs(ny - c);
            if(dist >= k) { continue; }
            
            k--;
            nowX = nx; nowY = ny;
            nowCmd += cmd[i];
            break;
        }
    }
    
    return nowCmd;
}