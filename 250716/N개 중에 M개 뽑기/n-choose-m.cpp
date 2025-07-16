#include <iostream>
#include <vector>
using namespace std;

vector<int> nums;
int N, M;

void SelectNum(int step, int now)
{
    if(step == M)
    {
        for(int num: nums) cout << num << ' ';
        cout << '\n';
    }

    for(int i = now + 1; i <= N; i++)
    {
        nums.push_back(i);
        SelectNum(step + 1, i);
        nums.pop_back();
    }
}

int main() {
    cin >> N >> M;

    // Please write your code here.
    SelectNum(0, 0);
    return 0;
}
