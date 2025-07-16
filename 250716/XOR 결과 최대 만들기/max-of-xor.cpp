#include <iostream>
#include <vector>
using namespace std;

int n, m;
int A[20];
vector<int> nums;
int ans;

void SelectNum(int step, int now)
{
    if(step == m)
    {
        int res = nums[0];
        for(int i = 1; i < m; i++)
        {
            res ^= nums[i];
        } 
        ans = ans < res ? res : ans;
        return;
    }

    for(int i = now + 1; i < n; i++)
    {
        nums.push_back(A[i]);
        SelectNum(step+1, i);
        nums.pop_back();
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    // Please write your code here.
    SelectNum(0, -1);
    cout << ans;
    return 0;
}