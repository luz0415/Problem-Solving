#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> weight;

void Input()
{
    cin >> N;
    weight.resize(N);
    for(int i = 0; i < N; i++)
    {
        cin >> weight[i];
    }
}


void Solve()
{
    sort(weight.begin(), weight.end());

    if(weight[0] != 1)
    {
        cout << 1;
        return;
    }
    
    long long sum = weight[0];
    
    for(int i = 1; i < N; i++)
    {
        if(sum < weight[i] && sum + 1 != weight[i])
        {
            break;
        }
        sum += weight[i];
    }
    cout << sum + 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();
    Solve();
}