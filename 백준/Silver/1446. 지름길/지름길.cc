#include <bits/stdc++.h>
using namespace std;

int N, D;
vector<pair<pair<int, int>, int>> shortcuts;

void Input()
{
    cin >> N >> D;
    shortcuts.resize(N);

    for(int i = 0; i < N; i++)
    {
        cin >> shortcuts[i].first.first >> shortcuts[i].first.second >> shortcuts[i].second;
    }
}

int DFS(int node, int drive, int prev)
{
    int now = shortcuts[node].first.second;
    drive += shortcuts[node].first.first - prev;
    drive += shortcuts[node].second;

    int minDrive = drive + D - now;
    for(int i = node + 1; i < N; i++)
    {
        if(shortcuts[i].first.first >= now && shortcuts[i].first.second <= D)
        {
            int nextDrive = DFS(i, drive, now);
            minDrive = min(minDrive, nextDrive);
        }
    }
    return minDrive;
}

void Solve()
{
    sort(shortcuts.begin(), shortcuts.end());

    int ans = D;
    for(int i = 0; i < N; i++)
    {
        if(shortcuts[i].first.second <= D)
        {
            ans = min(ans, DFS(i, 0, 0));
        }
    }

    cout << ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();
    Solve();
}