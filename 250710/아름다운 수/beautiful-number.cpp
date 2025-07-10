#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> list;
int ans;
void SelectNumber(int step)
{
    if(step > n)
    {
        for(int i = 0; i < n; i++)
        {
            int idx = i;
            int checkStep = list[i];
            while(checkStep > 0)
            {
                if(list[idx] != list[i])
                {
                    return;
                }
                checkStep--;
                if(checkStep > 0) i++;
            }
        }
        ans++;
        return;
    }

    for(int i = 1; i <= 4; i++)
    {
        list.push_back(i);
        SelectNumber(step+1);
        list.pop_back();
    }
}

int main() {
    cin >> n;

    // Please write your code here.
    SelectNumber(1);
    cout << ans;
    return 0;
}
