#include <string>
#include <vector>
#include <map>
#include <utility>
#include <cmath>
#include <queue>
#include <iostream>

using namespace std;

vector<map<int, int>> dices;
int diceCount;
vector<bool> isADice;
int maxWinCount;
vector<int> answer;

void GetBattle()
{
    // 수, 그 수가 나오는 횟수
    map<int, int> ASum;
    map<int, int> BSum;
    map<int, int> prevASum;
    map<int, int> prevBSum;
    
    for(int i = 0 ; i < diceCount; i++)
    {
        if(isADice[i])
        {
            ASum.clear();
            if(prevASum.size() == 0)
            {
                for(auto iter = dices[i].begin(); iter != dices[i].end(); iter++ )
                {
                    ASum[iter->first] += iter->second;
                }
            }
            else
            {
                for(auto iter = dices[i].begin(); iter != dices[i].end(); iter++ )
                {
                    for(auto iter2 = prevASum.begin(); iter2 != prevASum.end(); iter2++)
                    {
                        ASum[iter->first+iter2->first] += iter->second * iter2->second;   
                    }
                }
            }
            prevASum = ASum;
        }
        else
        {
            BSum.clear();
            if(prevBSum.size() == 0)
            {
                for(auto iter = dices[i].begin(); iter != dices[i].end(); iter++ )
                {
                    BSum[iter->first] += iter->second;
                }
            }
            else
            {
                for(auto iter = dices[i].begin(); iter != dices[i].end(); iter++ )
                {
                    for(auto iter2 = prevBSum.begin(); iter2 != prevBSum.end(); iter2++)
                    {
                        BSum[iter->first+iter2->first] += iter->second * iter2->second;   
                    }
                }
            }
            prevBSum = BSum;
        }
    }
    
    // {{Num, 플레이어 0or1}, Num의 수}
    priority_queue<pair<pair<int, int>, int>> pq;
    int ACount, BCount;
    ACount = BCount = pow(6, diceCount/2);
    for(auto iter = ASum.begin(); iter != ASum.end(); iter++ )
    {
        pq.push({{iter->first, 0}, iter->second});
    }    
    for(auto iter = BSum.begin(); iter != BSum.end(); iter++ )
    {
        pq.push({{iter->first, 1}, iter->second});
    }
    
    int winCount = 0;
    int lastNum = 0;
    while(!pq.empty())
    {
        int num = pq.top().first.first;
        int player = pq.top().first.second;
        int count = pq.top().second;
        pq.pop();
        if(player == 0)
        {
            winCount += BCount * count;
            ACount -= count;
        }
        else { BCount -= count; }
        lastNum = num;
    }
    
    if(winCount > maxWinCount)
    {
        maxWinCount = winCount;
        int count = 0;
        for(int i = 0; i < diceCount; i++)
        {
            if(isADice[i]) answer[count++] = i+1;
        }
    }
}

void Combination(int idx, int count, int depth)
{
    if (idx >= diceCount) return;
    if(idx != -1) isADice[idx] = true;
    if(count == depth)
    {
        GetBattle();
        isADice[idx] = false;
        return;
    }
    
    for(int i = idx + 1; i < diceCount; i++)
    {
        Combination(i, count+1, depth);
    }
    if(idx != -1) isADice[idx] = false;
}

vector<int> solution(vector<vector<int>> dice) {
    diceCount = dice.size();
    dices.assign(diceCount, map<int, int>());
    for(int i = 0; i < diceCount; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            dices[i][dice[i][j]]++;
        }
    }
    
    isADice.assign(diceCount, false);
    answer.assign(diceCount/2, 0);
    Combination(-1, 0, diceCount/2);
    cout << maxWinCount;
    return answer;
}