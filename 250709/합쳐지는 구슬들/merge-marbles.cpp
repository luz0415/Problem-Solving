#include <iostream>
#include <utility>
#include <map>
using namespace std;

int n, m, t;
pair<int, int> bead[2500];
int d[2500];
int w[2500];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int main() {
    cin >> n >> m >> t;

    for (int i = 0; i < m; i++) {
        int x, y;
        char dir;
        cin >> x >> y >> dir >> w[i];
        x--; y--; bead[i] = {x, y};
        if(dir == 'U') d[i] = 0;
        else if(dir == 'D') d[i] = 1;
        else if(dir == 'L') d[i] = 2;
        else d[i] = 3;
    }

    for(int time = 0; time < t; time++)
    {
        map<pair<int, int>, int> beadMap;
        for(int i = 0; i < m; i++)
        {
            if(w[i] == 0) continue;
            bead[i].first += dx[d[i]];
            bead[i].second += dy[d[i]];

            if(bead[i].first < 0 || bead[i].first >= n || bead[i].second < 0 || bead[i].second >= n)
            {
                bead[i].first -= dx[d[i]];
                bead[i].second -= dy[d[i]];
                if(d[i] == 0 || d[i] == 2) d[i]++;
                else d[i]--;
            }

            if(beadMap.find(bead[i]) != beadMap.end())
            {
                int existIdx = beadMap[bead[i]];
                if(i < existIdx)
                {
                    w[existIdx] += w[i];
                    w[i] = 0;
                }
                else
                {
                    w[i] += w[existIdx];
                    w[existIdx] = 0;
                    beadMap[bead[i]] = i;
                }
            }
            else
            {
                beadMap[bead[i]] = i;
            }
        }
    }

    int count = 0;
    int bestWeight = 0;
    for(int i = 0; i < m; i++)
    {
        if(w[i] > 0)
        {
            count++;
            bestWeight = bestWeight < w[i] ? w[i] : bestWeight;
        }
    }

    cout << count << ' ' << bestWeight;
    return 0;
}
