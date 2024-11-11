#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int> > rooms;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void Input()
{
	cin >> n;
	
	rooms.assign(n, vector<int>(n));
	for(int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for(int j = 0; j < n; j++)
		{
			rooms[i][j] = s[j] -'0';
		}
	}
}

void Solve()
{
	int ans;
	
	deque<pair<int, int> > dq;
	dq.push_back({0, 0});
	
	vector<vector<int> > blackRooms(n, vector<int>(n, -1));
	blackRooms[0][0] = 0;
	while(!dq.empty())
	{
		int nowX = dq.front().first;
		int nowY = dq.front().second;
		dq.pop_front();
		
		if(nowX == n-1 && nowY == n-1)
		{
			ans = blackRooms[nowX][nowY];
			break;
		}
		
		for(int i = 0; i < 4; i++)
		{
			int nx = dx[i] + nowX;
			int ny = dy[i] + nowY;
			
			if(nx >= 0 && nx < n && ny >= 0 && ny < n)
			{
				if(blackRooms[nx][ny] != -1) continue;
				
				if(rooms[nx][ny] == 1)
				{
					dq.push_front({nx, ny});
					blackRooms[nx][ny] = blackRooms[nowX][nowY];
				}
				else
				{
					dq.push_back({nx, ny});
					blackRooms[nx][ny] = blackRooms[nowX][nowY] + 1;
				}
			}
		}
	}
	
	cout << ans;
}

int main()
{
  	ios::sync_with_stdio(false);
  	cin.tie(NULL);
  	cout.tie(NULL);
  	
  	Input();
  	Solve();
}