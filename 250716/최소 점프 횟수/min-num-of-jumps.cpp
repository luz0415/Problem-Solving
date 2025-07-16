#include <iostream>
using namespace std;

int N;
int count;
int ans = -1;
int circle[10];

void Jump(int step)
{
    if(step >= N-1)
    {
        if(step == N-1)
        {
            if(ans == -1) ans = count;
            else ans = ans > count ? count : ans;
        }
        return;
    }

    for(int i = 1; i <= circle[step]; i++)
    {
        count++;
        Jump(step + i);
        count--;
    }
}

int main() {
    // Please write your code here.
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> circle[i];
    }

    Jump(0);
    cout << ans;
    return 0;
}