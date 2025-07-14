#include <iostream>
#include <vector>
using namespace std;

int K, N;
vector<int> ans;
void SelectNum(int step)
{
    if(step > N)
    {
        for(int num : ans)
        {
            cout << num << ' ';
        } 
        cout << '\n';
        return;
    }

    for(int i = 1; i <= K; i++)
    {
        if(step >= 3)
        {
            if(ans[step-3] == ans[step-2] && ans[step-3] == i) continue;
        }
        
        ans.push_back(i);
        SelectNum(step+1);
        ans.pop_back();
    }
}

int main() {
    cin >> K >> N;

    // Please write your code here.
    SelectNum(1);
    return 0;
}
