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
int n;

void add_edge(int node)
{
	for (auto edge: ad[node])
		dist.push(edge);
}

long long prim(int pn)
{
	long long ret = 0;
	for (int i = 1; i <= pn; i++)
		selected[i] = false;
	dist.push(PII(0, 1));
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
			return (long long)INF;
		ret += min_dist;
		selected[now] = true;
		add_edge(now);
	}
	return ret;
}

int main()
{
	int tmp;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> tmp;
			if (tmp == 0)
				continue;
			ad[i].push_back({tmp, j});
		}
	}
	cout << prim(n);
	return 0;
}
