#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
using pii = pair<int, int>;

bool cmp(pii& p1, pii& p2)
{
    if (p1.second == p2.second)
    {
        return p1.first < p2.first;
    }

    return p1.second < p2.second;
}

int main() {
    int N; cin >> N;
    vector<pii> v;

    for (int i = 0; i < N; i++)
    {
        int s, e; cin >> s >> e;
        v.push_back({s, e});
    }

    sort(v.begin(), v.end(), cmp);
    
    int now = v[0].second;
    int count = 1;
    for (int i = 1; i < N; i++)
    {
        if (now <= v[i].first)
        {
            now = v[i].second;
            count++;
        }
    }

    cout << count;

    return 0;
}