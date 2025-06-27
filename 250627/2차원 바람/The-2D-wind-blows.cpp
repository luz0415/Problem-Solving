#include <iostream>

using namespace std;

int n, m, q;
int a[100][100];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void BlowWind(int r1, int c1, int r2, int c2)
{
    int tmp = a[r1][c2];
    for(int c = c2; c > c1; c--)
    {
        a[r1][c] = a[r1][c-1];
    }
    int tmp2 = a[r2][c2];
    for(int r = r2; r > r1; r--)
    {
        a[r][c2] = a[r-1][c2];
    }
    a[r1+1][c2] = tmp;
    tmp = a[r2][c1];
    for(int c = c1; c < c2; c++)
    {
        a[r2][c] = a[r2][c+1];
    }
    a[r2][c2-1] = tmp2;
    for(int r = r1; r < r2; r++)
    {
        a[r][c1] = a[r+1][c1];
    }
    a[r2-1][c1] = tmp;
}

int main() {
    cin >> n >> m >> q;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) cin >> a[i][j];

    // Please write your code here.
    for (int i = 0; i < q; i++) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        r1--; c1--; r2--; c2--;
        BlowWind(r1, c1, r2, c2);

        int tmp[100][100] = {0,};
        for(int r = r1; r <= r2; r++)
        {
            for(int c = c1; c <= c2; c++)
            {
                int sum = a[r][c];
                int count = 1;

                for(int d = 0; d < 4; d++)
                {
                    int nx = r + dx[d];
                    int ny = c + dy[d];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

                    count++;
                    sum += a[nx][ny];
                }
                tmp[r][c] = sum / count;
            }
        }

        for(int r = r1; r <= r2; r++)
        {
            for(int c = c1; c <= c2; c++)
            {
                a[r][c] = tmp[r][c];
            }
        }
    }

    for(int r = 0; r < n; r++)
    {
        for(int c = 0; c < m; c++)
        {
            cout << a[r][c] << " ";
        }
        cout << '\n';
    }
    return 0;
}
