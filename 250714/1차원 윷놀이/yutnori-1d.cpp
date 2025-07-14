#include <iostream>

using namespace std;

int n, m, k;
int nums[12];
int horseLoc[5];
int ans;

void SelectHorse(int turn)
{
    if(turn == n)
    {
        int res = 0;
        for(int i = 1; i <= k; i++)
        {
            if(horseLoc[i] >= m-1) res++;
        }

        ans = ans < res ? res : ans;
        return;
    }

    for(int i = 1; i <= k; i++)
    {
        horseLoc[i] += nums[turn];
        SelectHorse(turn+1);
        horseLoc[i] -= nums[turn];
    }
}

int main() {
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // Please write your code here.
    SelectHorse(0);
    cout << ans;
    return 0;
}
