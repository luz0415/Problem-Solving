#include <iostream>
using namespace std;
using ll = long long;

// N명이 살고 있는 위치와 이동속도가 주어짐
// 모두가 도착하는 데 걸리는 시간이 최소인 위치에 가기위해 걸리는 시간...?
// 특정 초를 잡을 수 있나? 1~1e9까지 해서

// 특정 초 안에 서로 겹치는 min max를 구해서 전부 겹치면 가능 아님 불가능?

int N;
int x[100000];
int v[100000];

bool IsPossible(double time)
{
    double xMin = x[0] - time * v[0];
    double xMax = x[0] + time * v[0];

    for (int i = 1; i < N; i++)
    {
        double nowMin = x[i] - time * v[i];
        double nowMax = x[i] + time * v[i];

        xMin = max(xMin, nowMin);
        xMax = min(xMax, nowMax);
    }
    return xMin <= xMax;
}

double BinarySearch()
{
    double L = 0, R = 1e9;
    int count = 0;

    while (count <= 100)
    {
        count++;
        double mid = (L+R) / 2;

        if (IsPossible(mid))
        {
            R = mid;
        }
        else
        {
            L = mid;
        }
    }

    return R;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> x[i];
    }
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }

    cout << fixed; cout.precision(4);
    cout << BinarySearch();

    return 0;
}