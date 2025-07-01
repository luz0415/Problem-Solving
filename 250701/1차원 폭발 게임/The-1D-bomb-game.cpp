#include <iostream>

using namespace std;

int n, m;
int numbers[100];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    // Please write your code here.
    bool isExplosed = false;
    do{
        isExplosed = false;
        int now = -1;
        int nowCount = 0;
        for(int i = 0; i < n; i++)
        {
            if(now != numbers[i])
            {
                if(nowCount >= m)
                {
                    isExplosed = true;
                    for(int j = i-1; j > i-1-(nowCount); j--)
                    {
                        numbers[j] = 0;
                    }
                }
                now = numbers[i];
                nowCount = 1;
            }
            else nowCount++;
        }
        
        if(nowCount >= m)
        {
            isExplosed = true;
            for(int j = n-1; j > n-1-(nowCount); j--)
            {
                numbers[j] = 0;
            }
        }

        int tmp[100] = {0,};
        int tmpIdx = 0;
        for(int i = n-1; i >= 0; i--)
        {
            if(numbers[i] != 0)
            {
                tmp[tmpIdx++] = numbers[i];
            }
        }

        n = tmpIdx;
        for(int i = 0; i < n; i++)
        {
            numbers[i] = tmp[n-i-1];
        }
    }while(isExplosed);

    cout << n << endl;
    for(int i = 0; i < n; i++)
    {
        cout << numbers[i] << endl;
    }
    return 0;
}
