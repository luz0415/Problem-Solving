#include <string>
#include <vector>
#include <cmath>

using namespace std;

string ChangeBinary(long long num)
{
    string binary = "";
    while(num > 0)
    {
        if(num % 2 == 1)
        {
            binary = "1" + binary;
        }
        else
        {
            binary = "0" + binary;
        }
        num /= 2;
    }
    
    return binary;
}

bool CanBinaryTree(const string& binary, int now, int prev)
{
    if(prev >= 0)
    {
        if(binary[prev] == '0' && binary[now] == '1')
        {
            return false;
        }
    }
    
    bool flag = true;
    int diff = abs(now-prev);
    if(diff >= 2)
    {
        flag = CanBinaryTree(binary, now + diff/2, now);
        if(flag) flag = CanBinaryTree(binary, now - diff/2, now);   
    }
    return flag;
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    
    for(int i = 0; i < numbers.size(); i++)
    {
        string binary = ChangeBinary(numbers[i]);
        
        int fullBinaryCount = 1;
        for(int base = 2; fullBinaryCount < binary.length(); base++)
        {
            fullBinaryCount = pow(2, base) - 1;
        }
        
        while(binary.length() < fullBinaryCount)
        {
            binary = "0" + binary;
        }
        
        if(binary[fullBinaryCount / 2] == '0')
        {
            answer.push_back(0);
            continue;
        }
        
        bool canBinaryTree = CanBinaryTree(binary, fullBinaryCount / 2, -1);
        answer.push_back((int)canBinaryTree);
    }
    return answer;
}