#include <iostream>
#include <vector>
using namespace std;

int n, m;
int x[20], y[20];
vector<int> selectIdx;
int ans = 20000;

int Dist(int x1, int x2, int y1, int y2)
{
    return (x1-x2) * (x1-x2) + (y1-y2) * (y1-y2);
}

void SelectNum(int step)
{
    if(selectIdx.size() == m)
    {
        for(int i = 0; i < m; i++)
        {
            for(int j = i + 1; j < m; j++)
            {
                int dist = Dist(x[selectIdx[i]], x[selectIdx[j]], y[selectIdx[i]], y[selectIdx[j]]);
                cout << dist;
                if(dist < ans) ans = dist;
            }
        }
        return;
    }
    if(step == n) return;
    
    selectIdx.push_back(step);
    SelectNum(step+1);
    selectIdx.pop_back();

    SelectNum(step+1);
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    SelectNum(0);
    cout << ans;
    return 0;
}
