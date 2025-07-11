#include <iostream>

using namespace std;

int n;
int x1[15], x2[15];
int x1Max;
int ans, count;

void SelectLines(int start)
{
    if(start >= x1Max)
    {
        ans = ans < count ? count : ans;
        return;
    }

    for(int i = 0; i < n; i++)
    {
        if(start >= x1[i]) { continue; }

        count++;
        SelectLines(x2[i]);
        count--;
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x1[i] >> x2[i];
        x1Max = x1[i] > x1Max ? x1[i] : x1Max;
    }

    // Please write your code here.
    SelectLines(0);
    cout << ans;
    return 0;
}
