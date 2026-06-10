#include <iostream>
using namespace std;

int main() {
    int N; cin >> N;
    int price[100000] = {};

    for (int i = 0; i < N; i++)
    {
        cin >> price[i];
    }

    int ans = 0;
    int minPrice = price[0];

    for (int i = 1; i < N; i++)
    {
        if (price[i] > minPrice)
        {
            ans = max(ans, price[i] - minPrice);
        }
        else if (price[i] < minPrice)
        {
            minPrice = price[i];
        }
    }

    cout << ans;
    return 0;
}