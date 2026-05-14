#include <iostream>
#include <algorithm>
using namespace std;

string A, B;
int arr[200000];

bool IsPossible(int idx)
{
    int newArr[200000] = {};
    for (int i = 0; i < idx; i++)
    {
        newArr[i] = arr[i];
    }

    sort(newArr, newArr+idx);

    int newArrIdx = 0;
    int BIdx = 0;
    for (int i = 0; i < A.length() && BIdx < B.length(); i++)
    {
        if (newArrIdx < idx && newArr[newArrIdx] == i)
        {
            newArrIdx++; continue;
        }
        
        if (A[i] == B[BIdx])
        {
            BIdx++;
        }
    }

    return BIdx == B.length();
}

int BinarySearch()
{
    int L = 0, R = A.length();
    int ans = -1;

    while (L <= R)
    {
        int mid = (L+R) / 2;

        if (IsPossible(mid))
        {
            L = mid + 1;
            ans = mid;
        }
        else
        {
            R = mid - 1;
        }
    }
    return ans;
}

int main() {
    cin >> A >> B;
    for (int i = 0; i < A.length(); i++)
    {
        cin >> arr[i]; arr[i]--;
    }

    cout << BinarySearch() + 1;
    return 0;
}