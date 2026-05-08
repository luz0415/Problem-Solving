#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

int N;
pair<int, int> lines[100000];

int BinarySearch()
{
    int L = 1, R= 1e9;
    int ans = 0;
    while (L <= R)
    {
        // 점은 mid 이상 떨어져야 함
        int mid = (L+R) / 2;

        int cur = lines[0].first;
        int count = 1;
        for (int i = 1; i < N; i++)
        {
            if (cur + mid <= lines[i].second)
            {
                cur = min(max(cur + mid, lines[i].first), lines[i].second);
                count++;
            }
            else
            {
                break;
            }
        }

        if (count == N)
        {
            L = mid + 1;
            ans = max(ans, mid);
        }
        else
        {
            R = mid - 1;
        }
    }

    return ans;
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> lines[i].first >> lines[i].second;
    }
    sort(lines, lines+N);

    cout << BinarySearch();
    return 0;
}