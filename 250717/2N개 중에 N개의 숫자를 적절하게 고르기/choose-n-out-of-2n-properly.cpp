#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int n;
int num[20];
int sum;
vector<int> nums;
int ans = 200000;

void SelectNum(int step, int idx)
{
    if(step == n)
    {
        int halfSum = 0;
        for(int number: nums)
        {
            halfSum += number;
        }

        int diff = abs(sum-2*halfSum);
        ans = min(diff, ans);
        return;
    }

    for(int i = idx; i < 2*n; i++)
    {
        nums.push_back(num[i]);
        SelectNum(step+1, idx+1);
        nums.pop_back();
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < 2 * n; i++) {
        cin >> num[i];
        sum += num[i];
    }

    // Please write your code here.
    SelectNum(0, 0);
    cout << ans;
    return 0;
}
