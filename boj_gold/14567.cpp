#include <iostream>
#include <queue>
#include <vector>
using namespace std;


vector<int> adj[1002];
int indeg[1002];
int ans[1002];
int n, m, a, b;
int cnt = 1;

void topo_sort()
{
	queue<int> q;
	for (int i = 1; i <= n; i++)
		if (indeg[i] == 0) q.push(i);
	while (!q.empty())
	{
		queue<int> nowq;
		while (!q.empty())
		{
			nowq.push(q.front());
			q.pop();
		}
		while (!nowq.empty())
		{
			int cur = nowq.front(); nowq.pop();
			ans[cur] = cnt;
			for (int i = 0; i < adj[cur].size(); i++)
			{
				int nxt = adj[cur][i];
				indeg[nxt]--;
					if (indeg[nxt] == 0) q.push(nxt);
			}
		}
		cnt++;
	}
	for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
}

int main()
{
	cin >> n >> m;
	while (m--)
	{
		cin >> a >> b;
		adj[a].push_back(b);
		indeg[b]++;
	}
	topo_sort();
}