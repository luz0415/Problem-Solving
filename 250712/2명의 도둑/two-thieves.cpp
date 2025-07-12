#include <iostream>
#include <map>
#include <utility>
#include <cmath>
using namespace std;

int n, m, c;
int weight[10][10];
map<pair<int, int>, int> values;
int value;

void CaculateValue(pair<int, int> coord, int w, int step)
{
    if(step == m)
    {
        if(values.find(coord) != values.end())
        {
            values[coord] = values[coord] < value ? value : values[coord];
        }
        else
        {
            values[coord] = value;
        }
        return;
    }

    int nowWeight = weight[coord.first][coord.second+step];

    if(w + nowWeight <= c)
    {
        value += nowWeight * nowWeight;
        CaculateValue(coord, w + nowWeight, step + 1);
        value -= nowWeight * nowWeight;
    }

    CaculateValue(coord, w, step+1);
}

int main() {
    cin >> n >> m >> c;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> weight[i][j];
        }
    }

    // Please write your code here.
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j <= n-m; j++) 
        {
            value = 0;
            CaculateValue({i, j}, 0, 0);
        }
    }

    int ans = 0;
    for (int x1 = 0; x1 < n; x1++) 
    {
        for (int y1 = 0; y1 <= n-m; y1++) 
        {
            for (int x2 = 0; x2 < n; x2++) 
            {
                for (int y2 = 0; y2 <= n-m; y2++) 
                {
                    if(x1 == x2 && (abs(y1-y2) < m)) continue;
                    int valueSum = values[{x1, y1}] + values[{x2, y2}];
                    ans = ans < valueSum ? valueSum : ans;
                }
            }
        }
    }

    cout << ans;
    return 0;
}