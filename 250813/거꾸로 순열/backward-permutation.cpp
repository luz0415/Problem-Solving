#include <iostream>
#include <vector>
using namespace std;

int n;
vector<bool> visited;
vector<int> nums;

void SelectNum(int step)
{
    if(step == n)
    {
        for(int num: nums)
        {
            cout << num << ' ';
        }cout << '\n';
        return;
    }

    for(int i = n; i >= 1; i--)
    {
        if(visited[i]) continue;
        visited[i] = true;
        nums.push_back(i);
        SelectNum(step+1);
        visited[i] = false;
        nums.pop_back();
    }
}

int main() {
    cin >> n;
    visited.assign(n, false);

    // Please write your code here.
    SelectNum(0);
    return 0;
}
