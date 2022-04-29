#include <iostream>
#include <queue>
using namespace std;

struct var
{
	int x;
	int y;
	int dis;
};

struct cmp
{
	bool operator()(var a, var b)
	{
		if (a.dis != b.dis)
			return a.dis > b.dis;
		if (a.x != b.x)
			return a.x > b.x;
		return a.y > b.y;
	}
};

int n;
int map[22][22];
int vis[22][22];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
var shark;
int sharksize = 2;
int howmany;
int movetime;
priority_queue<var, vector<var>, cmp> smaller;
queue<var> q;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 9)
			{
				shark.x = i;
				shark.y = j;
				shark.dis = 0;
				vis[i][j] = 1;
				q.push(shark);
			}
		}
	while (1)
	{
		while (!q.empty())
		{
			var cur = q.front();
			q.pop();
			for (int i = 0; i < 4; i++)
			{
				var now;
				now.x = cur.x + dx[i];
				now.y = cur.y + dy[i];
				now.dis = cur.dis + 1;
				if (!smaller.empty() && now.dis > smaller.top().dis)
					break;
				if (now.x < 0 || now.x >= n || now.y < 0 || now.y >= n || vis[now.x][now.y] == 1)
					continue;
				if (sharksize == map[now.x][now.y] || map[now.x][now.y] == 0)
				{
					vis[now.x][now.y] = 1;
					q.push(now);
				}
				else if (sharksize > map[now.x][now.y])
				{
					vis[now.x][now.y] = 1;
					smaller.push(now);
				}
			}
		}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				vis[i][j] = 0;
		if (!smaller.empty())
		{
			map[smaller.top().x][smaller.top().y] = 9;
			map[shark.x][shark.y] = 0;
			movetime += smaller.top().dis;
			shark.x = smaller.top().x;
			shark.y = smaller.top().y;
			shark.dis = 0;
			vis[shark.x][shark.y] = 1;
			q.push(shark);
			while (!smaller.empty())
				smaller.pop();
			howmany++;
			if (howmany == sharksize)
			{
				sharksize++;
				howmany = 0;
			}
		}
		else
			break;
	}
	cout << movetime;
}
