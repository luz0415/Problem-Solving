#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(int coin, vector<int> cards) {
    set<int> startCards; set<int> addCards;
    int n = cards.size();
    for(int i = 0; i < n / 3; i++)
    {
        startCards.insert(cards[i]);
    }
    
    bool flag = true;
    int round = 0;
    int idx = n / 3;
    while(flag)
    {
        round++;
        if (idx >= n) break;
        
        flag = false;
        addCards.insert(cards[idx++]);
        addCards.insert(cards[idx++]);
        
        for(int card : startCards)
        {
            if(startCards.find((n+1)-card) != startCards.end())
            {
                startCards.erase(startCards.find(card));
                startCards.erase(startCards.find((n+1)-card));
                flag = true;
                break;
            }
        }
        
        if(!flag && coin > 0)
        {
            for(int card : startCards)
            {
                if(addCards.find((n+1)-card) != addCards.end())
                {
                    startCards.erase(startCards.find(card));
                    addCards.erase(addCards.find((n+1)-card));
                    flag = true;
                    coin -= 1;
                    break;
                }
            }
        }
        
        if(!flag && coin > 1)
        {
            for(int card : addCards)
            {
                if(addCards.find((n+1)-card) != addCards.end())
                {
                    addCards.erase(addCards.find(card));
                    addCards.erase(addCards.find((n+1)-card));
                    flag = true;
                    coin -= 2;
                    break;
                }
            }
        }
    }
    
    return round;
}