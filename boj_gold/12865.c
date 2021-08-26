#include <stdio.h>

int map[101][100001] = { 0, };
int w[100] = { 0 };
int v[100] = { 0 };

int max(int a, int b)
{
	return (a > b ? a : b);
}

int bag(int n, int k)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			if (w[i] > j)
				map[i][j] = map[i - 1][j];
			else
				map[i][j] = max(map[i - 1][j - w[i]] + v[i], map[i - 1][j]);
		}
	}
	return (map[n][k]);
}

int main()
{
	int n, k;

	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d %d", &w[i], &v[i]);
	printf("%d\n", bag(n, k));
	return 0;
}
