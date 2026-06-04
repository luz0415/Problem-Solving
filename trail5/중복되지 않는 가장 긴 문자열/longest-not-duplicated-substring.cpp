#include <iostream>
#include <unordered_map>
using namespace std;

string word;

int main() {
    cin >> word;
    int ans = 0;
    unordered_map<char, int> um;
    int j = 0;
    for (int i = 0; i < word.length(); i++)
    {
        while (um[word[i]] >= 1)
        {
            um[word[j++]]--;
        }

        um[word[i]]++;
        ans = max(ans, i-j+1);
    }

    cout << ans;
    return 0;
}
