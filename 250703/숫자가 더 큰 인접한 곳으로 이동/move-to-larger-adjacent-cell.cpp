#include <iostream>

using namespace std;

int n;
int r, c;
int a[100][100];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int main() {
    cin >> n >> r >> c;
    r--; c--;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    // Please write your code here.
    cout << a[r][c] << " ";
    bool isContinue = false;
    do{
        isContinue = false;
        for(int i = 0; i < 4; i++)
        {
            int nx = r + dx[i];
            int ny = c + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            
            if(a[nx][ny] > a[r][c])
            {
                isContinue = true;
                cout << a[nx][ny] << " ";
                r = nx; c = ny;
                break;
            }
        }
    }while(isContinue);
    return 0;
}
