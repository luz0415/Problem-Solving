#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

bool cmp(const string& a, const string& b)
{
    return a + b > b + a;
}

int main() {
    int N; cin >> N;
    
    string arr[50000] = {};

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr+N, cmp);
    string s = "";
    for (int i = 0; i < N; i++)
    {
        s += arr[i];
    }
    cout << s;


    return 0;
}