#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int degree[10002];
int tim[10002];
int answer[10002];
vector<int> adj[10002];
int N, t, num, tmp;
int ans;

void topo_sort()
{
	queue<int> q;
	for (int i = 1; i <= N; i++)
	{
		if (degree[i] == 0)
		{
			q.push(i);
			answer[i] = tim[i];
		}
	}
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (int i = 0; i < adj[cur].size(); i++)
		{
			int nxt = adj[cur][i];
			degree[nxt]--;
			answer[nxt] = max(answer[nxt], answer[cur]);
			if (degree[nxt] == 0)
			{
				q.push(nxt);
				answer[nxt] += tim[nxt];
			}
		}
	}
}

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> t >> num;
		tim[i] = t;
		degree[i] = num;
		while (num--)
		{
			cin >> tmp;
			adj[tmp].push_back(i);
		}
	}
	topo_sort();
	for (int i = 1; i <= N; i++)
		ans = max(ans, answer[i]);
	cout << ans;
}