#include <iostream>

using namespace std;

int n, t;
int l[200];
int r[200];
int d[200];

int main() {
    cin >> n >> t;

    for (int i = 0; i < n; i++) cin >> l[i];

    for (int i = 0; i < n; i++) cin >> r[i];

    for (int i = 0; i < n; i++) cin >> d[i];

    // Please write your code here.
    for(int time = 0; time < t; time++)
    {
        int tmp = l[n-1];
        for(int i = n-1; i > 0; i--)
        {
            l[i] = l[i-1];
        }
        int tmp2 = r[n-1];
        for(int i = n-1; i > 0; i--)
        {
            r[i] = r[i-1];
        }
        r[0] = tmp;
        l[0] = d[n-1];
        for(int i = n-1; i > 0; i--)
        {
            d[i] = d[i-1];
        }
        d[0] = tmp2;
    }

    for (int i = 0; i < n; i++) cout << l[i] << " ";
    cout << endl;
    for (int i = 0; i < n; i++) cout << r[i] << " ";
    cout << endl;
    for (int i = 0; i < n; i++) cout << d[i] << " ";
    return 0;
}
