#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int points[100000];
int st, ed;

int LowerBound(int find)
{
    int L = 0, R = n-1;
    int idx = n;

    while (L <= R)
    {
        int mid = (L+R) / 2;
        if (find <= points[mid])
        {
            idx = min(idx, mid);
            R = mid-1;
        }
        else
        {
            L = mid+1;
        }
    }

    return idx;
}

int UpperBound(int find)
{
    int L = 0, R = n-1;
    int idx = n;

    while (L <= R)
    {
        int mid = (L+R) / 2;
        if (find < points[mid])
        {
            idx = min(idx, mid);
            R = mid-1;
        }
        else
        {
            L = mid+1;
        }
    }

    return idx;
}
int main() {
    cin.tie(0);
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> points[i];
    }
    sort(points, points+n);

    for (int i = 0; i < m; i++) {
        cin >> st >> ed;
        int lb = LowerBound(st);
        if (lb == n)
        {
            cout << 0;
        }
        else
        {
            cout << UpperBound(ed) - lb;
        }
        cout << '\n';
    }

    return 0;
}
