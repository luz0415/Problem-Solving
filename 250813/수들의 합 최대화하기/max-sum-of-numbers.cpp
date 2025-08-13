#include <iostream>
#include <vector>
using namespace std;

int n;
int grid[10][10];
vector<bool> visited;
vector<int> nums;
int ans = 0;

void SelectNum(int step)
{
    if(step == n)
    {
        int sum = 0;
        for(int i = 0; i < n; i++)
        {
            sum += grid[i][nums[i]];
        }
        ans = sum > ans ? sum : ans;
        return;
    }

    for(int i = 0; i < n; i++)
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

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    visited.assign(n, false);

    // Please write your code here.
    SelectNum(0);
    cout << ans;
    return 0;
}
