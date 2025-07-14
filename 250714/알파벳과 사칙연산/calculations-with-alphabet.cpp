#include <iostream>
#include <string>
using namespace std;

string expression;
int numByAlphabet[6];
int ans;

int CalculateExpression()
{
    int res = numByAlphabet[expression[0] - 'a'];

    for(int idx = 1; idx < expression.size(); idx+=2)
    {
        if(expression[idx] == '+')
        {
            res += numByAlphabet[expression[idx+1] - 'a'];
        }
        else if(expression[idx] == '-')
        {
            res -= numByAlphabet[expression[idx+1] - 'a'];
        }        
        else if(expression[idx] == '*')
        {
            res *= numByAlphabet[expression[idx+1] - 'a'];
        }
    }
    return res;
}

void SelectNum(int step)
{
    if(step == 6)
    {
        int result = CalculateExpression();
        ans = result > ans ? result : ans;
        return;
    }

    for(int i = 1; i <= 4; i++)
    {
        numByAlphabet[step] = i;
        SelectNum(step + 1);
    }
}

int main() {
    cin >> expression;

    // Please write your code here.
    SelectNum(0);
    cout << ans;
    return 0;
}
