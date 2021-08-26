#include <iostream>
#include <queue>

using namespace std;

int n;
int map[125][125];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

typedef struct position
{
	int val;
	int x;
	int y;
}	pos;

struct cmp
{
	bool operator()(pos &a, pos &b)
	{
		if (a.val != b.val)
			return (a.val > b.val);
		return (0);
	}
};

int link()
{
	int ans[125][125] = { 0 };
	priority_queue<pos, vector<pos>, cmp> pq;

	for (int i = 0; i < n; i++)
		for (int k = 0; k < n; k++)
			ans[i][k] = 2147483647;
	ans[0][0] = map[0][0];
	pq.push({ans[0][0], 0, 0});
	while (!pq.empty())
	{
		pos now = pq.top();
		pq.pop();
		if (now.val != ans[now.y][now.x])
			continue;
		for (int i = 0; i < 4; i++)
		{
			int newx = now.x + dx[i];
			int newy = now.y + dy[i];
			if (newx < 0 || newx >= n || newy < 0 || newy >= n)
				continue;
			if (ans[newy][newx] > (ans[now.y][now.x] + map[newy][newx]))
			{
				ans[newy][newx] = ans[now.y][now.x] + map[newy][newx];
				pq.push({ans[newy][newx], newx, newy});
			}
		}
	}
	return ans[n - 1][n - 1];
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);
	int cnt = 1;

	while (1)
	{
		cin >> n;
		if (n == 0)
			break;
		for (int i = 0; i < n; i++)
			for (int k = 0; k < n; k++)
				cin >> map[i][k];
		cout << "Problem " << cnt++ << ": " << link() << "\n";
	}
	return 0;
}
