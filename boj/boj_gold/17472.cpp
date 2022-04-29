#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#define PII pair<int, int>
#define INF 2147483647
using namespace std;

int n, m;
int map[12][12];
vector<PII> ad[7];
priority_queue<PII, vector<PII>, greater<PII> > dist;
bool selected[7];
int cnt = 1;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void add_edge(int node)
{
	for (int i = 0; i < ad[node].size(); i++)
		dist.push(ad[node][i]);
}

int prim(int pn)
{
	int ret = 0;
	for (int i = 1; i <= pn; i++)
		selected[i] = false;
	dist.push(PII(0, 1));
	for (int i = 1; i <= pn; i++)
	{
		int now;
		int min_dist = INF;
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

void bfs(int x, int y)
{
	queue<PII> q;
	q.push({x, y});
	while (!q.empty())
	{
		PII cur = q.front();
		q.pop();
		map[cur.first][cur.second] = cnt;
		for (int i = 0; i < 4; i++)
		{
			int nowx = cur.first + dx[i];
			int nowy = cur.second + dy[i];
			if (nowx <= 0 || nowx > n || nowy <= 0 || nowy > m)
				continue;
			if (map[nowx][nowy] == 0)
				q.push({nowx, nowy});
		}
	}
}

void find_near(int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 1; j <= max(n, m); j++)
		{
			int nowx = x + dx[i] * j;
			int nowy = y + dy[i] * j;
			if (nowx <= 0 || nowx > n || nowy <= 0 || nowy > m)
				continue;
			if (map[nowx][nowy] == map[x][y])
				break;
			if (map[nowx][nowy] >= 1)
			{
				if (j <= 2)
					break;
				else
				{
					ad[map[x][y]].push_back({j - 1, map[nowx][nowy]});
					break;
				}
			}
		}
	}
}

void make_bridge()
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			if (map[i][j] == 0)
			{
				bfs(i, j);
				cnt++;
			}
		}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			if (map[i][j] >= 1)
				find_near(i, j);
		}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	int tmp;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			cin >> tmp;
			map[i][j] = tmp - 1;
		}
	make_bridge();
	int ans = prim(cnt - 1);
	if (ans == INF)
		cout << -1;
	else
		cout << ans;
	return 0;
}
