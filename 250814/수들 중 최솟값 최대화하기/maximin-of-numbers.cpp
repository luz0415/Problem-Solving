#include <iostream>
#include <vector>
using namespace std;

int n;
int grid[10][10];
vector<bool> visited;
vector<int> nums;
int ans;

void SelectNum(int step)
{
    if(step == n)
    {
        int min = 10000;
        for(int num: nums)
        {
            min = min > num ? num : min;
        }
        ans = ans < min ? min : ans;
        return;
    }

    for(int i = 0; i < n; i++)
    {
        if(visited[i]) continue;
        visited[i] = true;
        nums.push_back(grid[step][i]);
        SelectNum(step+1);
        visited[i] = false;
        nums.pop_back();
    }
}


int main() {
    cin >> n;
    visited.assign(n, false);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    // Please write your code here.
    SelectNum(0);
    cout << ans;
    return 0;
}
