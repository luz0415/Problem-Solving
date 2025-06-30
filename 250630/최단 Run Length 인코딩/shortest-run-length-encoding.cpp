#include <iostream>
#include <string>

using namespace std;

string A;

string shift(const string& s, int shiftNum)
{
    if(shiftNum == 0) { return s; }
    int length = s.length();
    string sub1 = s.substr(length-shiftNum, shiftNum);
    string sub2 = s.substr(0, length-shiftNum);

    return sub1 + sub2;
}

int RunLengthEncoding(const string& s)
{
    char nowChar = ' ';
    int nowCount = 0;
    int encodingLength = 0;

    for(char c : s)
    {
        if(c != nowChar)
        {
            encodingLength += 2;
            nowChar = c;
            nowCount = 1;
        }
        else { nowCount++; }
    }
    
    if(nowCount == 10) encodingLength++;
    return encodingLength;
}

int main() {
    cin >> A;

    // Please write your code here.
    int N = A.length();
    int ans = 21;
    for(int i = 0; i < N; i++)
    {
        string shiftStr = shift(A, i);
        int length = RunLengthEncoding(shiftStr);
        ans = ans > length ? length : ans;
    }

    cout << ans;
    return 0;
}
