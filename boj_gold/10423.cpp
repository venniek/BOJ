#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#define PII pair<int, int>
#define INF 2147483647
using namespace std;

vector<PII> ad[1005];
priority_queue<PII, vector<PII>, greater<PII> > dist;
bool selected[1005];
int plant[1005];
int n, m, k;

void add_edge(int node)
{
	for (auto edge: ad[node])
		dist.push(edge);
}

int prim(int pn)
{
	int ret = 0;
	for (int i = 1; i <= pn; i++)
		selected[i] = false;
	for (int i = 0; i < k; i++)
		dist.push(PII(0, plant[i]));
	for (int i = 1; i <= pn; i++)
	{
		int now = -1; int min_dist = INF;
		while (!dist.empty())
		{
			now = dist.top().second;
			if (!selected[now])
			{
				min_dist = dist.top().first;
				break;
			}
			dist.pop();
		}
		if (min_dist == INF)
			return INF;
		ret += min_dist;
		selected[now] = true;
		add_edge(now);
	}
	return ret;
}

int main()
{
	int a, b, c;
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++)
		cin >> plant[i];
	for (int i = 1; i <= m; i++)
	{
		cin >> a >> b >> c;
		ad[a].push_back({c, b});
		ad[b].push_back({c, a});
	}
	cout << prim(n);
	return 0;
}
