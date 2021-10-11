#include <iostream>

using namespace std;

int n, m, h;
int a, b;
int map[32][12];
int ans = 4;

int check_ladder()
{
	for (int i = 1; i <= n; i++)
	{
		int start = i;
		for (int j = 1; j <= h; j++)
		{
			if (map[j][start] == 1)
				start++;
			else if (start > 1 && map[j][start - 1] == 1)
				start--;
		}
		if (start != i)
			return 0;
	}
	return 1;
}

void add_line(int row, int col, int cnt)
{
	if (cnt > 3)
		return ;
	if (check_ladder() == 1)
	{
		ans = min(ans, cnt);
		return ;
	}
	for (int i = row; i <= h; i++)
	{
		for (int j = 1; j < n; j++)
		{
			if (i == row && j <= col)
				continue;
			if (map[i][j] == 0)
			{
				if (j > 1 && map[i][j - 1] == 1)
					continue;
				if (j < n - 1 && map[i][j + 1] == 1)
					continue;
				map[i][j] = 1;
				add_line(i, j, cnt + 1);
				map[i][j] = 0;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m >> h;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		map[a][b] = 1;
	}
	add_line(1, 0, 0);
	if (ans == 4)
		cout << -1;
	else
		cout << ans;
	return 0;
}