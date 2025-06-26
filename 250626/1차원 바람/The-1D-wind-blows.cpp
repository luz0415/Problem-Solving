#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int n, m, q;
int a[100][100];

void BlowWind(int* arr, char d)
{
    if(d == 'L')
    {
        int tmp = arr[m-1];
        for(int i = m-1; i >= 1; i--)
        {
            arr[i] = arr[i-1];
        }
        arr[0] = tmp;
    }
    else
    {
        int tmp = arr[0];
        for(int i = 1; i < m; i++)
        {
            arr[i-1] = arr[i];
        }
        arr[m-1] = tmp;
    }
}

bool CanTransition(int r1, int r2)
{
    for(int i = 0; i < m; i++)
    {
        if(a[r1][i] == a[r2][i]) return true;
    }
    return false;
}

int main() {
    cin >> n >> m >> q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < q; i++) {
        int r;
        char d;
        cin >> r >> d;
        r--;
        // 바람 별로 진행
        BlowWind(a[r], d);
        // 행, 바람 방향, 전파 방향
        queue<pair<int, pair<char, int>>> q;
        d = (d == 'L') ? 'R' : 'L';
        q.push({r-1, {d, -1}});
        q.push({r+1, {d, 1}});

        while(!q.empty())
        {
            r = q.front().first;
            d = q.front().second.first;
            int tr = q.front().second.second;
            q.pop();

            if(r < 0 || r >= n) continue;
            if(!CanTransition(r, r-tr)) continue;
            BlowWind(a[r], d);
            d = d == 'L' ? 'R' : 'L';
            q.push({r+tr, {d, tr}});
        }

    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
