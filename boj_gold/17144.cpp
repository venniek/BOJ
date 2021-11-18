#include <iostream>
using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int map[55][55];
int r, c, t, ans;
int gong[2];

void spread()
{
	int minus[55][55] = {0, };
	int plus[55][55] = {0, };

	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; j++)
		{
			if (map[i][j] > 0)
			{
				for (int k = 0; k < 4; k++)
				{
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (nx <= 0 || nx > r || ny <= 0 || ny > c)
						continue;
					if (map[nx][ny] == -1)
						continue;
					plus[nx][ny] += map[i][j] / 5;
					minus[i][j] += map[i][j] / 5;
				}
			}
		}
	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; j++)
			map[i][j] += plus[i][j] - minus[i][j];
}

void wind()
{
	for (int i = gong[0] - 1; i > 1; i--)
		map[i][1] = map[i - 1][1];
	for (int i = 1; i < c; i++)
		map[1][i] = map[1][i + 1];
	for (int i = 1; i < gong[1]; i++)
		map[i][c] = map[i + 1][c];
	for (int i = c; i > 2; i--)
		map[gong[0]][i] = map[gong[0]][i - 1];
	map[gong[0]][2] = 0;
	for (int i = gong[1] + 1; i < r; i++)
		map[i][1] = map[i + 1][1];
	for (int i = 1; i < c; i++)
		map[r][i] = map[r][i + 1];
	for (int i = r; i > gong[1]; i--)
		map[i][c] = map[i - 1][c];
	for (int i = c; i > 2; i--)
		map[gong[1]][i] = map[gong[1]][i - 1];
	map[gong[1]][2] = 0;
}

int main()
{
	cin >> r >> c >> t;
	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == -1)
			{
				if (gong[0] == 0)
					gong[0] = i;
				else
					gong[1] = i;
			}
		}
	while (t--)
	{
		spread();
		wind();
	}
	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; j++)
		{
			if (map[i][j] > 0)
				ans += map[i][j];
		}
	cout << ans;
}
