#include <iostream>
#include <utility>
#include <map>
using namespace std;

int T;
int N;
pair<double, double> bead[100];
int w[100];
int d[100];
double dx[] = {0.5, -0.5, 0, 0};
double dy[] = {0, 0, -0.5, 0.5};

int main() {
    cin >> T;

    for (int t = 0; t < T; t++) {
        cin >> N;

        for (int i = 0; i < N; i++) {
            double x, y;
            char dir;
            cin >> x >> y >> w[i] >> dir;
            bead[i] = {y, x};
            if(dir == 'U') d[i] = 0;
            else if(dir == 'D') d[i] = 1;
            else if(dir == 'L') d[i] = 2;
            else if(dir == 'R') d[i] = 3;
        }
    
        bool isContinue = true;
        int time = 0;
        int lastCollideTime = -1;
        while(isContinue)
        {
            isContinue = false;
            time++;
            map<pair<double, double>, int> nextBeadMap;
            for(int i = 0; i < N; i++)
            {  
                if(bead[i].first < -1000 || bead[i].first > 1000 || bead[i].second < -1000 || bead[i].second > 1000) continue;
                isContinue = true;
                
                bead[i].first += dx[d[i]];
                bead[i].second += dy[d[i]];

                if (nextBeadMap.find(bead[i]) != nextBeadMap.end()) 
                {
                    // 다른 구슬이 있다면
                    int existIdx = nextBeadMap[bead[i]];
                    if(w[i] > w[existIdx] || (w[i] == w[existIdx] && i > existIdx))
                    {
                        nextBeadMap[bead[i]] = i;
                        bead[existIdx] = {-2000, -2000};
                    }
                    else
                    {
                        bead[i] = {-2000, -2000};
                    }
                    lastCollideTime = time;
                }
                else 
                {
                    // 다른 구슬 없음
                    nextBeadMap.insert({bead[i], i});
                }
            }
        }
        cout << lastCollideTime << '\n';
    }

    return 0;
}