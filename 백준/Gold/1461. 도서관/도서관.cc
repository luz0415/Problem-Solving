#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> books;

void Input()
{
	cin >> N >> M;
	books.assign(N, 0);
	
	for(int i = 0; i < N; i++)
	{
		cin >> books[i];
	}
	sort(books.begin(), books.end());
}

int BookSteps(int startIdx, int endIdx)
{
	if(startIdx == endIdx) { return abs(books[startIdx]); }

	int steps;	
	if(abs(books[startIdx]) >= abs(books[endIdx]))
	{	
		steps = abs(books[startIdx]);
		if(books[startIdx] * books[endIdx] < 0)
		{
			steps += abs(books[endIdx]);
		}	
	}
	else
	{	
		steps = abs(books[endIdx]);
		if(books[startIdx] * books[endIdx] < 0)
		{
			steps += abs(books[startIdx]);
		}
	}
	
	//cout << "start: " << startIdx << " end: " << endIdx << " >" << steps << endl;
	return steps;
}

void Solve()
{
	int finalSteps = 0;
	int left = 0, right = N-1;
	
	int leftFirstSteps = 0, rightFirstSteps = 0;
	bool isFirst = true;
	while(true)
	{
		int nextLeft = left + M;
		if(nextLeft > N || books[nextLeft - 1] > 0) break;
		
		finalSteps += BookSteps(left, nextLeft - 1) * 2;
		if(isFirst)
		{
			leftFirstSteps = BookSteps(left, nextLeft - 1);
			isFirst = false;
		}
		left = nextLeft;
	}
	
	isFirst = true;
	while(true)
	{
		int nextRight = right - M;
		if(nextRight < -1 || books[nextRight + 1] < 0) break;
		
		finalSteps += BookSteps(nextRight + 1, right) * 2;
		if(isFirst)
		{
			rightFirstSteps = BookSteps(nextRight + 1, right);
			isFirst = false;
		}
		right = nextRight;
	}
	if(left <= right)
	{
		finalSteps += BookSteps(left, right) * 2;
	}
	
	if(leftFirstSteps == 0 && rightFirstSteps == 0)
	{
		finalSteps -= max(abs(books[left]), abs(books[right]));
	}
	else
	{
		finalSteps -= max(leftFirstSteps, rightFirstSteps);
	}
	cout << finalSteps;
}

int main()
{
  	ios::sync_with_stdio(false);
  	cin.tie(NULL);
  	cout.tie(NULL);
  	
  	Input();
  	Solve();
}