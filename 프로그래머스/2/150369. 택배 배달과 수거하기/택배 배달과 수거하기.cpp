#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> Deliveries;
vector<int> Pickups;

void Delivery(int& topDeliveryIdx, int cap)
{
    while(cap > 0 && topDeliveryIdx >= 0)
    {
        if(cap >= Deliveries[topDeliveryIdx])
        {
            cap -= Deliveries[topDeliveryIdx];
            Deliveries[topDeliveryIdx] = 0;
            while(topDeliveryIdx >= 0 && Deliveries[topDeliveryIdx] == 0) topDeliveryIdx--;
        }
        else
        {
            Deliveries[topDeliveryIdx] -= cap;
            cap = 0;
        }
    }
}

void Pickup(int& topPickupIdx, int cap)
{
    while(cap > 0 && topPickupIdx >= 0)
    {
        if(cap >= Pickups[topPickupIdx])
        {
            cap -= Pickups[topPickupIdx];
            Pickups[topPickupIdx] = 0;
            while(topPickupIdx >= 0 && Pickups[topPickupIdx] == 0) topPickupIdx--;
        }
        else
        {
            Pickups[topPickupIdx] -= cap;
            cap = 0;
        }
    }
}

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    Deliveries = deliveries; Pickups = pickups;
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
        // cout << answer << " " << topDeliveryIdx << " " << topPickupIdx << endl;
        Delivery(topDeliveryIdx, cap);
        Pickup(topPickupIdx, cap);
    }
    return answer;
}