#include <string>
#include <vector>
#include <stack>

using namespace std;
const int MAX = 1000000;

// 자신이 가리키는 노드들
vector<vector<int>> toNode;
// 자신을 가리키는 노드들
vector<vector<int>> fromNode;

vector<int> solution(vector<vector<int>> edges) {
    for(int i = 0; i < MAX; i++)
    {
        vector<int> v;
        toNode.push_back(v);
        fromNode.push_back(v);
    }
    
    for(int i = 0; i < edges.size(); i++)
    {
        int from = edges[i][0];
        int to = edges[i][1];
        
        toNode[from].push_back(to);
        fromNode[to].push_back(from);
    }
    
    int centerNode;
    for(int i = 0; i < MAX; i++)
    {
        if(toNode[i].size() >= 2 && fromNode[i].size() == 0)
        {
            centerNode = i;
            break;
        }
    }
    
    int donut = 0, stick = 0, eight = 0;
    
    for(int i = 0; i < toNode[centerNode].size(); i++)
    {
        int startNode = toNode[centerNode][i];
        
        vector<bool> visited;
        visited.assign(MAX, false);
        
        stack<int> st;
        st.push(startNode);
        
        while(!st.empty())
        {
            int now = st.top();
            st.pop();
            
            if(toNode[now].size() >= 2)
            {
                eight++;
                break;
            }
            else if(toNode[now].size() == 0)
            {
                stick++;
                break;
            }
            else if(visited[now]) 
            {
                donut++;
                break;
            }
            
            visited[now] = true;
            
            for(int j = 0; j < toNode[now].size(); j++)
            {
                int next = toNode[now][j];
                st.push(next);
            }
        }
    }

    
    vector<int> answer = {centerNode, donut, stick, eight};
    return answer;
}