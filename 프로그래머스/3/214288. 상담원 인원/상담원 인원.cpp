#include <string>
#include <vector>
#include <queue>
#include <functional>  
#include <iostream>

using namespace std;

// combinations[i][j] = i번째 조합, j번째 멘토가 할당받을 유형
vector<vector<int>> combinations;
vector<int> tmpCombination;
int K;
int N;

// waitingTimes[i][j] = i유형에서 j+1명의 멘토가 있을때 대기시간
vector<vector<int>> waitingTimes;

void Combination(int index, int num){
    if(index == N-K){
        combinations.push_back(tmpCombination);
        return;
    }

    for(int i = num; i <= K; i++){
        tmpCombination[index] = i;
        Combination(index + 1, i);
    }
}

int solution(int k, int n, vector<vector<int>> reqs) {
    K = k; N = n;
    
    waitingTimes.assign(k, vector<int>(n, n-k));
    for(int type = 0; type < k; type++)
    {
        queue<pair<int, int>> typeReqs;
        for(int i = 0; i < reqs.size(); i++)
        {
            if(reqs[i][2] - 1 == type)
            {
                typeReqs.push({reqs[i][0], reqs[i][1]});
            }
        }
        
        for(int mentor = 1; mentor <= (n-k+1); mentor++)
        {
            queue<pair<int, int>> queueReqs(typeReqs);
            // 끝나는 시간
            priority_queue<int, vector<int>, greater<int>> nowReqs;
            
            for(int i = 0; i < mentor && i < typeReqs.size(); i++)
            {
                int endTime = queueReqs.front().first + queueReqs.front().second;
                queueReqs.pop();
                nowReqs.push(endTime);
            }
            
            int nowTime = 0;
            int waitingTime = 0;
            
            while(!nowReqs.empty())
            {
                nowTime = nowReqs.top();
                nowReqs.pop();
                
                if(queueReqs.empty()) continue;
                
                int endTime;
                if(queueReqs.front().first < nowTime)
                {
                    endTime = nowTime + queueReqs.front().second;
                    waitingTime += nowTime - queueReqs.front().first;
                }
                else
                {
                    endTime = queueReqs.front().first + queueReqs.front().second;
                }
                
                queueReqs.pop();
                nowReqs.push(endTime);
            }
            
            waitingTimes[type][mentor-1] = waitingTime;
        }
    }
    
    tmpCombination.assign(n-k, 1);
    Combination(0, 1);
    
    int minWaitingTime = 123456789;
    int tmpWaitingTime = 0;
    
    vector<int> mentorNums(k, 1);
    for(int i = 0; i < combinations.size(); i++)
    {
        for(int j = 0; j < combinations[i].size(); j++)
        {
            cout << combinations[i][j];
            mentorNums[combinations[i][j]-1]++;
        }
        cout <<endl;
        
        for(int type = 0; type < k; type++)
        {
            tmpWaitingTime += waitingTimes[type][mentorNums[type]-1];
        }
        minWaitingTime = min(minWaitingTime, tmpWaitingTime);
        tmpWaitingTime = 0;
        mentorNums.assign(k, 1);
    }
    
    return minWaitingTime;
}