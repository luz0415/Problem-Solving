#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int emoticonCount;
int userCount;
vector<int> Emoticons;
vector<vector<int>> Users;

vector<vector<int>> answerOptions;
map<int, int> sumByDiscount;

void CheckPurchase()
{
    vector<int> options(2, 0);
    
    for(int i = 0; i < userCount; i++)
    {
        int purchasePrice = 0;
        int discountStd = Users[i][0];
        int registerStd = Users[i][1];
        
        for(int discount = 40; discount >= 10 && discountStd <= discount; discount -= 10)
        {
            purchasePrice += sumByDiscount[discount];
        }
        
        if(registerStd <= purchasePrice)
        {
            options[0]++;
            purchasePrice = 0;
        }
        options[1] += purchasePrice;
    }
    
    //cout << options[0] << " " << options[1] << endl;
    answerOptions.push_back(options);
}

void DFS(int idx, int discount)
{
    int price = Emoticons[idx] / 100 * (100-discount);
    sumByDiscount[discount] += price;
    
    if(idx == emoticonCount - 1)
    {
        CheckPurchase();
        sumByDiscount[discount] -= price;
        return;
    }
    
    for(int i = 1; i <= 4; i++)
    {
        DFS(idx+1, i * 10);
    }
    sumByDiscount[discount] -= price;
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    Emoticons = emoticons;
    Users = users;
    
    emoticonCount = emoticons.size(); 
    userCount = users.size(); 
    for(int i = 1; i <= 4; i++)
    {
        DFS(0, i * 10);
    }
    
    sort(answerOptions.begin(), answerOptions.end());
    return answerOptions[answerOptions.size() - 1];
}