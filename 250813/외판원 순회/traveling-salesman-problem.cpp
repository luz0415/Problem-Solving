#include <iostream>
#include <vector>
using namespace std;

int n;
int A[10][10];
int ans = 1E9;

vector<int> nums;
vector<bool> visited;

void SelectNum(int step)
{
    if(step == n)
    {
        int sum = 0;
        for(int i = 0; i < n-1; i++)
        {
            sum += A[nums[i]][nums[i+1]];
        }
        sum += A[nums[n-1]][0];
        ans = ans > sum ? sum : ans;
        return;
    }

    for(int i = 0; i < n; i++)
    {
        if(visited[i]) continue;
        if(A[nums[step-1]][i] == 0) continue;
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
            cin >> A[i][j];
        }
    }

    // Please write your code here.
    visited.assign(n, false);
    visited[0] = true;
    nums.push_back(0);
    SelectNum(1);

    cout << ans;
    return 0;
}
