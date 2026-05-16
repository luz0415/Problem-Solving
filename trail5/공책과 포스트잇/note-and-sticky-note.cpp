#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// N개의 공책
// 공책의 번호는 놓여있던 포스트잇에 적힘
// i번 공책의 번호가 다른 포스트잇에 적힌 횟수 c[i]
// c[i]가 h이상인 공책들이 h개 이상 있는 경우 중 h의 최댓값 > hIndex

// h가 가능한지 안한지 체크
// 작은거부터 쫘라락 넣기? 아님. 그러면 하나만 버리고 나머지에 몰빵 이런 정책이 안됨
// 아!!!!!!!! K개랑 제일 가까운 애들부터 채워넣어서 가능한지 체크!!!!!!!

int N, K, L;
int c[100000];

// 추가적으로 만들 포스트잇 최대 개수 K
// 포스트잇에 적을 수 있는 번호 수 L
// 포스트잇마다 같은 공책의 번호는 한개

bool IsPossible(int h)
{
    int count = 0;
    long long maxPosted = (long long)K * L;

    for (int i = N-1; i >= 0; i--)
    {
        if (c[i] >= h)
        {
            count++;
        }
        else if (h - c[i] <= K && maxPosted >= (long long) h - c[i])
        {
            maxPosted -= (long long) h - c[i];
            count++;
        }
    }

    return count >= h;
}

int BinarySearch()
{
    int L = 0, R = 100000;
    int hIndex = 0;

    while (L <= R)
    {
        int mid = (L+R) / 2;

        if (IsPossible(mid))
        {
            L = mid + 1;
            hIndex = max(hIndex, mid);
        }
        else
        {
            R = mid - 1;
        }
    }

    return hIndex;
}

int main() {
    cin >> N >> K >> L;
    for (int i = 0; i < N; i++)
    {
        cin >> c[i];
    }
    sort(c, c+N);

    cout << BinarySearch();

    return 0;
}