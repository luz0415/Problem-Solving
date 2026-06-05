#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    string s;
    int K;
    cin >> s;
    cin >> K;

    unordered_map<char, int> um;

    int now = 0;
    int ans = 0;
    for (int i = 0; i < s.length(); i++)
    {
        while (um.size() >= K && um.find(s[i]) == um.end())
        {
            um[s[now]]--;
            if (um[s[now]] == 0)
            {
                um.erase(s[now]);
            }
            now++;
        }
        um[s[i]]++;
        ans = max(ans, i-now+1);
    }

    cout << ans;
    return 0;
}