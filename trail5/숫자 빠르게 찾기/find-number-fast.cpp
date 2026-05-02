#include <iostream>

using namespace std;

int n, m;
int arr[100000];

int BinarySearch(int find)
{
    int L = 0, R = n;

    while (L <= R)
    {
        int mid = (L + R) / 2;

        if (arr[mid] == find)
        {
            return mid + 1;
        }
        else if (arr[mid] < find)
        {
            L = mid + 1;
        }
        else
        {
            R = mid - 1;
        }
    }

    return -1;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;

        cout << BinarySearch(x) << '\n';
    }

    return 0;
}
