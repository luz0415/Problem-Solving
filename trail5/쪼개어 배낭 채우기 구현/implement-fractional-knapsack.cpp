#include <iostream>
#include <tuple>
#include <queue>
using namespace std;

int N, M;

int main() {
    cin >> N >> M;

    // vPerw, w, v
    priority_queue<tuple<double, int, int>> pq;

    for (int i = 0; i < N; i++) {
        int w, v;
        cin >> w >> v;
        pq.push({(double)v/w, w, v});
    }

    double ans = 0;
    while (M > 0 && !pq.empty())
    {
        auto [vPerw, w, v] = pq.top();
        pq.pop();

        if (M >= w)
        {
            M -= w;
            ans += v;
        }
        else
        {
            ans += vPerw * M;
            M = 0;
        }
    }

    cout << fixed; cout.precision(3);
    cout << ans;
    return 0;
}
