#include <iostream>
using namespace std;

int n, m;
int r, c, d;
int cnt;
int map[51][51];
int lx[4] = {-1, 0, 1, 0};
int ly[4] = {0, -1, 0, 1};
int bx[4] = {0, -1, 0, 1};
int by[4] = {1, 0, -1 ,0};

int is_wall(int c, int r)
{
	for (int i = 0; i < 4; i++)
	{
		if (map[r + ly[i]][c + lx[i]] == 0)
			return (0);
	}
	return (1);
}

void change_d(int *d)
{
	(*d)--;
	if (*d == -1)
		*d = 3;
}

int main()
{
	cin >> n >> m;
	cin >> r >> c >> d;
	for (int i = 0; i < n; i++)
	{
        for (int k = 0; k < m; k++)
			cin >> map[i][k];
	}
	map[r][c] = 2;
	cnt++;
	while (1)
	{
		if (is_wall(c, r) == 1)
		{
			if (map[r + by[d]][c + bx[d]] == 1)
				break;
			else
			{
				c += bx[d];
				r += by[d];
			}
		}
		else
		{
			if (map[r + ly[d]][c + lx[d]] == 0)
			{
				c += lx[d];
				r += ly[d];
				cnt++;
			}
			change_d(&d);
			map[r][c] = 2;
		}
	}
	cout << cnt;
	return 0;
}
