#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int done[1500];
int map[1500][1500];

int sum_done(int n)
{
	int sum = 0;

	for (int i = 0; i < n; i++)
	{
		if (done[i] == 0)
			return (1);
	}
	return (0);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	priority_queue<int, vector<int>, greater<int> > q;
	int n;
	int col;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int k = 0; k < n; k++)
			cin >> map[i][k];
	}
	for (int i = n - 1; i >= 0; i--)
	{
		for (int k = n - 1; k >= 0; k--)
		{
			if (done[k] == 1)
				continue;
			q.push(map[i][k]);
			if (map[i][k] == q.top())
				col = k;
			if (q.size() > n)
			{
				done[col] = 1;
				q.pop();
			}
		}
		if (sum_done(n) == 0)
			break;
	}
	cout << q.top();
	return 0;
}
