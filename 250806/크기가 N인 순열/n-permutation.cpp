#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> nums;
vector<bool> visit;

void SelectNum(int idx)
{
    if(idx == n)
    {
        for(int num : nums)
        {
            cout << num << ' ';
        }cout << '\n';
    }

    for(int i = 1; i <= n; i++)
    {
        if(visit[i]) continue;
        visit[i] = true;
        nums.push_back(i);
        SelectNum(idx+1);
        visit[i] = false;
        nums.pop_back();
    }
}

int main() {
    cin >> n;
    visit.assign(n+1, false);

    // Please write your code here.
    SelectNum(0);
    return 0;
}
