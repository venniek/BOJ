#include <iostream>
#include <queue>
#include <vector>
#include <unistd.h>
using namespace std;

vector<int> adj[505];
int indeg[505];
int t, n, m;
int links[505][505];

void init()
{
	for (int i = 0; i < 505; i++)
	{
		adj[i].clear();
		indeg[i] = 0;
		for (int j = 0; j < 505; j++)
			links[i][j] = 0;
	}
}

void topo_sort()
{
	queue<int> q;
	vector<int> result;
	for (int i = 1; i <= n; i++)
		if (indeg[i] == 0) q.push(i);
	while (!q.empty())
	{
		int cur = q.front(); q.pop();
		result.push_back(cur);
		for (int i = 0; i < adj[cur].size(); i++)
		{
			int nxt = adj[cur][i];
			indeg[nxt]--;
				if (indeg[nxt] == 0) q.push(nxt);
		}
	}
	if (result.size() != n)
	{
		cout << "IMPOSSIBLE";
		return ;
	}
	for (int i = 0; i < n; i++) cout << result[i] << ' ';
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> t;
	int a, b;
	while (t--)
	{
		init();
		cin >> n;
		int rank[505] = {0, };
		for (int i = 1; i <= n; i++)
			cin >> rank[i];
		for (int i = 1; i < n; i++)
			for (int j = i + 1; j <= n; j++)
			{
				links[rank[i]][rank[j]] = 1;
				links[rank[j]][rank[i]] = 2;
			}
		cin >> m;
		for (int i = 0; i < m; i++)
		{
			cin >> a >> b;
			links[a][b] = links[a][b] % 2 + 1;
			links[b][a] = links[b][a] % 2 + 1;
		}
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
			{
				if (links[i][j] == 1)
				{
					adj[i].push_back(j);
					indeg[j]++;
				}
			}
		int sum = 0;
		for (int i = 1; i <= n; i++)
			sum += indeg[i];
		if (sum != (n - 1) * n / 2)
			cout << "?";
		else
			topo_sort();
		cout << '\n';
	}
}
