#include <iostream>

using namespace std;

int map[501][501];
int invite[501];

int main()
{
	int n, m;
	int a, b;
	int cnt = 0;

	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		map[a][b] = 1;
		map[b][a] = 1;
	}
	for (int i = 2; i <= n; i++)
	{
		if (map[1][i] == 1)
		{
			invite[i] = 1;
			for (int k = 2; k <= n; k++)
			{
				if (map[i][k] == 1)
					invite[k] = 1;
			}
		}
	}
	for (int i = 2; i <= n; i++)
	{
		if (invite[i])
			cnt++;
	}
	cout << cnt;
	return 0;
}
