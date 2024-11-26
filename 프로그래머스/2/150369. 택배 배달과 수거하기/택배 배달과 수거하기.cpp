#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void DeliveryOrPickup(int& topIdx, vector<int>& homes, int cap)
{
    while(cap > 0 && topIdx >= 0)
    {
        if(cap >= homes[topIdx])
        {
            cap -= homes[topIdx];
            homes[topIdx] = 0;
            while(topIdx >= 0 && homes[topIdx] == 0) topIdx--;
        }
        else
        {
            homes[topIdx] -= cap;
            cap = 0;
        }
    }
}

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    int topDeliveryIdx = -1;
    int topPickupIdx = -1;
    
    for(int i = n - 1; i >= 0; i--)
    {
        if(deliveries[i] != 0)
        {
            topDeliveryIdx = i; break;
        }
    }    
    for(int i = n - 1; i >= 0; i--)
    {
        if(pickups[i] != 0)
        {
            topPickupIdx = i; break;
        }
    }
    
    long long answer = 0;
    while(topDeliveryIdx >= 0 || topPickupIdx >= 0)
    {
        answer += (max(topDeliveryIdx, topPickupIdx) + 1) * 2;
        DeliveryOrPickup(topDeliveryIdx, deliveries, cap);
        DeliveryOrPickup(topPickupIdx, pickups, cap);
    }
    return answer;
}