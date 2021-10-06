#include <iostream>
#include <queue>
using namespace std;

typedef struct xyz
{
	int x;
	int y;
	int z;
} xyz;

int tomato[102][102][102];
int n, m, h, ans, noans;
int dx[6] = {0, 0, 0, 0, 1, -1};
int dy[6] = {1, -1, 0, 0, 0, 0};
int dz[6] = {0, 0, 1, -1, 0, 0};
queue<xyz> q;

int main()
{
	cin >> m >> n >> h;
	for (int i = 1; i <= h; i++)
		for (int j = 1; j <= n; j++)
			for (int k = 1; k <= m; k++)
			{
				cin >> tomato[i][j][k];
				if (tomato[i][j][k] == 1)
					q.push({i, j, k});
			}
	q.push({0, 0, 0});
	while (!q.empty())
	{
		xyz now = q.front(); q.pop();
		if (now.x == 0 && now.y == 0 && now.z == 0)
		{
			ans++;
			continue;
		}
		for (int i = 0; i < 6; i++)
		{
			if (now.x + dx[i] <= 0 || now.y + dy[i] <= 0 || now.z + dz[i] <= 0
			|| now.x + dx[i] > h || now.y + dy[i] > n || now.z + dz[i] > m)
				continue;
			if (tomato[now.x + dx[i]][now.y + dy[i]][now.z + dz[i]] == 0)
			{
				tomato[now.x + dx[i]][now.y + dy[i]][now.z + dz[i]] = 1;
				q.push({now.x + dx[i], now.y + dy[i], now.z + dz[i]});
			}
		}
		if (!q.empty() && q.front().x == 0 && q.front().y == 0 && q.front().z == 0)
			q.push({0, 0, 0});
	}
	for (int i = 1; i <= h; i++)
		for (int j = 1; j <= n; j++)
			for (int k = 1; k <= m; k++)
			{
				if (tomato[i][j][k] == 0)
				{
					noans = 1;
					break;
				}
			}
	if (noans == 1)
		cout << -1;
	else
		cout << ans - 2;

}