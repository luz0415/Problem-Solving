#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

int main() {
    int N; cin >> N;
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < N; i++)
    {
        int num; cin >> num;
        pq.push(num);
    }
    int ans = 0;
    while (pq.size() >= 2)
    {
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        pq.push(a+b); ans += a+b;
    }

    cout << ans;

    return 0;
}