#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> work;
vector<int> relationCount;
vector<vector<int> > relation;

void Input()
{
    cin >> N;
    work.assign(N, 0);
    relationCount.assign(N, 0);
    relation.assign(N, vector<int>());

    for(int i = 0; i < N; i++)
    {
        cin >> work[i];
        cin >> relationCount[i];
        for(int j = 0; j < relationCount[i]; j++)
        {
            int w;
            cin >> w;
            w--;

            relation[i].push_back(w);
            relation[w].push_back(i);
        }
    }
}

void Solve()
{
    int time = 0;

    // 작업번호, 남은 작업시간 
    vector<pair<int, int> > nowWork;

    for(int i = 0; i < N; i++)
    {
        if(relationCount[i] == 0)
        {
            nowWork.push_back({i, work[i]});
        }
    }

    queue<int> justFinishedWork;
    while(!nowWork.empty())
    {
        time++;
        // cout << "Now Work: ";
        for(vector<pair<int,int> >::iterator it = nowWork.begin(); it != nowWork.end();) 
        {
            // cout << "{" << (*it).first << ", " << (*it).second << "} ";
            (*it).second--;

            if((*it).second == 0) {
                justFinishedWork.push((*it).first);
                it = nowWork.erase(it);
            }
            else 
            {
                it++;
            }
        }
        // cout << endl;

        while(!justFinishedWork.empty())
        {
            int finishedWork = justFinishedWork.front();
            // cout << finishedWork << endl;
            justFinishedWork.pop();

            for(int i = 0; i < relation[finishedWork].size(); i++)
            {
                int relatedWork = relation[finishedWork][i];
                if(relatedWork > finishedWork)
                {
                    
                    relationCount[relatedWork]--;
                    if(relationCount[relatedWork] == 0)
                    {
                        nowWork.push_back({relatedWork, work[relatedWork]});
                    }
                }
            }
        }
    }

    cout << time;

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();
    Solve();
}