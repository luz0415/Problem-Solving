#include <iostream>
#include <vector>
using namespace std;

vector<int> list;
int K, N;

void SelectNumber(int step)
{
    if(step > N)
    {
        for(int i = 0; i < N; i++) { cout << list[i] << ' ';}
        cout << '\n';
        return;
    }

    for(int i = 1; i <= K; i++)
    {
        list.push_back(i);
        SelectNumber(step+1);
        list.pop_back();
    }
 
}

int main() {
    cin >> K >> N;

    // Please write your code here.
    SelectNumber(1);
    return 0;
}
