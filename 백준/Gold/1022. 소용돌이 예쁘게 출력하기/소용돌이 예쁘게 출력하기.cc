#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> nums;
vector<int> minusminus(5001);
vector<int> plusminus(5001);
vector<int> minusplus(5001);

int r1, c1, r2, c2;

void Input()
{
    cin >> r1 >> c1 >> r2 >> c2;
}

int FindSwirlNum(int r, int c)
{
    int num = 1;
    if(c < 0 && abs(c) >= abs(r))
    {
        num = minusminus[c*-1] + r-c;
    }
    else if(r >= 0 && (r >= abs(c) || c == r+1))
    {
        num = plusminus[r] + c+r;
    }
    else if(c >= 0 && c >= abs(r))
    {
        num = minusplus[c] - (c+r);
    }
    else if(r < 0 && abs(r) >= abs(c))
    {
        num = minusplus[r*-1] + (-r-c);
    }

    return num;
}

int GetDigits(int num)
{
    int digits = 0;
    while(num > 0)
    {
        num /= 10;
        digits++;
    }

    return digits;
}

void Solve()
{
    minusminus[0] = 1;    plusminus[0] = 1;    minusplus[0] = 1;
    minusminus[1] = 5;    plusminus[1] = 7;    minusplus[1] = 3;
    for(int i = 2; i <= 5000; i++)
    {
        minusminus[i] = minusminus[i-1] + (minusminus[i-1] - minusminus[i-2] + 8);
        plusminus[i] = plusminus[i-1] + (plusminus[i-1] - plusminus[i-2] + 8);
        minusplus[i] = minusplus[i-1] + (minusplus[i-1] - minusplus[i-2] + 8);
    }
    
    nums.assign(r2-r1+1, vector<int>(c2-c1+1));
    int maxNum = 0;
    for(int r = r1; r <= r2; r++)
    {
        for(int c = c1; c <= c2; c++)
        {
            nums[r-r1][c-c1] = FindSwirlNum(r, c);
            maxNum = max(maxNum, nums[r-r1][c-c1]);
        }
    }

    int maxDigits = GetDigits(maxNum);
    for(int r = r1; r <= r2; r++)
    {
        for(int c = c1; c <= c2; c++)
        {
            int num = nums[r-r1][c-c1];
            int digit = GetDigits(num);

            string blank = " ";
            
            for(int i = 0; i < (maxDigits-digit); i++)
            {
                cout << blank;
            }

            cout << num << " ";
        }
        cout << "\n";
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