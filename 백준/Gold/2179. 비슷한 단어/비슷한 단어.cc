#include <bits/stdc++.h>
using namespace std;

typedef struct Node{
    char value;
    int count;
    unordered_map<char, Node*> children;
}Node;

unordered_map<char, Node*> trie;
int N;
vector<string> strs;

void Input()
{
    for(int i = 0; i < 26; i++)
    {
        Node* node = new Node();
        node->value = 'a' + i;
        node->count = 0;
        trie['a' + i] = node;
    }

    cin >> N;

    set<string> strsSet;
    for(int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        strs.push_back(s);
        strsSet.insert(s);
    }

    for(auto& s : strsSet)
    {
        Node* parentNode = trie[s[0]];
        parentNode->count++;

        for(int j = 1; j < s.length(); j++)
        {
            if(parentNode->children.count(s[j]) == 0)
            {
                Node* newNode = new Node();
                newNode->value = s[j];
                newNode->count = 1;
                parentNode->children[s[j]] = newNode;
            }
            else
            {
                parentNode->children[s[j]]->count++;
            }
            parentNode = parentNode->children[s[j]]; // 부모 노드를 업데이트
        }
    }
}

void Solve()
{	
    int prefixLength = 0;
    string prefix;

    for(int i = 0; i < strs.size(); i++)
    {
        char firstChar = strs[i][0];
        
        stack<pair<Node*, string>> st;
        string pre(1, firstChar);
        st.push({trie[firstChar], pre});

        while(!st.empty())
        {
            Node* nowNode = st.top().first;
            string nowPrefix = st.top().second;
            st.pop();

            if(nowPrefix.length() > prefixLength && nowNode->count >= 2)
            {
                prefix = nowPrefix;
                prefixLength = nowPrefix.length();
            }

            for(auto& child : nowNode->children)
            {
                if(child.second->count >= 2)
                {
                    st.push({child.second, nowPrefix + child.first});
                }
            }
        }
    }

    if(prefixLength == 0)
    {
        cout << strs[0] << '\n' << strs[1] << '\n';
        return;
    }
    
    int count = 0;
    for(string s : strs)
    {
        if(prefixLength > s.length()) continue;

        bool isPrefix = true;
        for(int j = 0; j < prefixLength; j++)
        {
            if(prefix[j] != s[j])
            {
                isPrefix = false;
                break;
            }
        }

        if(isPrefix)
        {
            cout << s << '\n';
            count++;
        }
        if(count == 2) break;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();
    Solve();
}
