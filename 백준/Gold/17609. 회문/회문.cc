#include <bits/stdc++.h>
using namespace std;

int T;
vector<string> strs;

void Input()
{
    cin >> T;
    strs.resize(T);
    for (int i = 0; i < T; i++)
    {
        cin >> strs[i];
    }
}

bool IsPalindrome(int& left, int& right, int strIdx)
{
    while(left < right)
    {
        if(strs[strIdx][left] != strs[strIdx][right])
        {
            return false;
        }
        left++; right--;
    }
    return true;
}

void Solve()
{
    for(int i = 0; i < T; i++)
    {
        int len = strs[i].length();
        int left = 0, right = len - 1;
        int ans = 0;

        if(!IsPalindrome(left, right, i))
        {
            int newLeft = left+1, newRight = right;
            if(IsPalindrome(newLeft, newRight, i))
            {
                ans = 1;
            }
            else if(IsPalindrome(newLeft=left, newRight=right-1, i))
            {
                ans = 1;
            }
            else
            {
                ans = 2;
            }
        }
        
        cout << ans << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();
    Solve();
}