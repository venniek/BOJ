#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#define PII pair<int, int>
using namespace std;

const int N = 200005;
vector<PII> ad[N];
priority_queue<PII, vector<PII>, greater<PII>> dist;
bool selected[N];
int m, n;
int x, y, z;

void add_edge(int node)
{
	for (auto edge : ad[node])
		dist.push(edge);
}

int prim(int pn)
{
	int ret = 0;
	int min_dist = 0;
	for (int i = 1; i <= pn; i++)
		selected[i] = false;
	dist.push(PII(0, 1));
	for (int i = 1; i <= pn; i++)
	{
		int now = -1;
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
		ret += min_dist;
		selected[now] = true;
		add_edge(now);
	}
	return ret;
}

int main()
{
	while (1)
	{
		int total = 0;
		for (int i = 0; i < N; i++)
		{
			while (!ad[i].empty())
				ad[i].pop_back();
		}
		while (!dist.empty())
			dist.pop();
		cin >> m >> n;
		if (m == 0 && n == 0)
			break;
		while (n--)
		{	
			cin >> x >> y >> z;
			ad[x + 1].push_back(PII(z, y + 1));
			ad[y + 1].push_back(PII(z, x + 1));
			total += z;
		}
		cout << total - prim(m) << "\n";
	}
	return 0;
}
