#include <iostream>
#include <algorithm>
#include <set>
#include <climits>
using namespace std;

// 두 점의 y좌표 차가 D 이상 되도록 할때,
// 이때 x좌표 차이가 최소가 되도록 하는 프로그램
// y좌표 차가 D이상이 될 수 없다면 -1 출력

// x좌표 기준으로 정렬해서
// set에 윈도우 형식으로 넣음
// set은 y기준으로 정렬
// y의 최댓값 - 최솟값이 D를 넘었다면? 둘의 x좌표 차이로 최소 갱신
// 이후 제일 앞에 있던 윈도우는 뺌 (얘로 최초로 D넘었으면 이것보다 x차이가 가벼우면서 D를 넘을수는 없음)

int main() {
    int N, D;
    cin >> N >> D;

    pair<int, int> coords[100000];
    for (int i = 0; i < N; i++)
    {
        cin >> coords[i].first >> coords[i].second;
    }

    sort(coords, coords+N);

    // y, x
    set<pair<int, int>> s;
        s.insert({coords[0].second, coords[0].first});
    int L = 0, R = 1;
    int ans = INT_MAX;
    while(L < N)
    {
        bool isOverD = (s.rbegin()->first - s.begin()->first) >= D;
        while (R < N && !isOverD)
        {
            s.insert({coords[R].second, coords[R].first});
            isOverD = (s.rbegin()->first - s.begin()->first) >= D;
            R++;
        }

        // D를 넘었음, 이때의 x좌표 차이로 답 갱신
        if(isOverD)
        {
            ans = min(ans, coords[R-1].first - coords[L].first);
        }
        s.erase({coords[L].second, coords[L].first});
        L++;
    }

    if (ans == INT_MAX) { cout << -1; }
    else { cout << ans; }
    return 0;
}