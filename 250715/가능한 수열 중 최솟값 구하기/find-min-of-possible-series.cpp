#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> nums;
bool isEnd = false;

void SelectNum(int step)
{
    if(step == n)
    {
        for(int num : nums) cout << num;
        isEnd = true;
        return;
    }

    for(int i = 4; i <= 6; i++)
    {
        bool CanNext = false;
        for(int seqLen = 1; seqLen <= (step/2 + step%2); seqLen++)
        {
            int firstSeqStart = step - (seqLen - 1);
            int secondSeqStart = firstSeqStart - seqLen;
            for(int idx = 0; idx < seqLen; idx++)
            {
                if(idx == seqLen-1) // 마지막 인덱스
                {
                    if(nums[secondSeqStart + idx] != i)
                    {
                        CanNext = true;
                        break;
                    }
                }
                else if(nums[firstSeqStart + idx] != nums[secondSeqStart + idx])
                {
                    CanNext = true;
                    break;
                }
                
                CanNext = false;
            }
            if(!CanNext) break;
        }

        if(!CanNext) continue;
        nums.push_back(i);
        SelectNum(step+1);
        nums.pop_back();
        
        if(isEnd) return;
    }
}


int main() {
    cin >> n;

    // Please write your code here.
    nums.push_back(4);
    SelectNum(1);
    return 0;
}
