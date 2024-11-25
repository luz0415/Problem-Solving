#include <bits/stdc++.h>
using namespace std;

// {{출발지, 도착지}, 시간}
vector<pair<pair<int, int>, int>> bus;
int N, M;

void Input()
{
    cin >> N >> M;
    for(int i = 0; i < M; i++)
    {
        int A, B, C;
        cin >> A >> B >> C;
        A--; B--;
        bus.push_back({{A, B}, C});
    }
}

void Solve()
{
    vector<long> time(N, INT_MAX);
    time[0] = 0;

    bool isMinusCycle = false;
    for(int i = 0; i <= N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            int start = bus[j].first.first;
            int end = bus[j].first.second;
            int t = bus[j].second;

            if(time[start] != INT_MAX && time[start] + t < time[end])
            {
                time[end] = time[start] + t;
                if(i == N) { isMinusCycle = true; }
            }
        }
    }

    if(isMinusCycle) { cout << -1; return; }

    for(int i = 1; i < N; i++)
    {
        if(time[i] == INT_MAX) cout << -1 << '\n';
        else cout << time[i] << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();
    Solve();
}