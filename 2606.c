#include <stdio.h>

int is_done[1001] = { 0 };
int link[1001][1001] = { 0, };

void DFS(int n, int v)
{
	is_done[v] = 1;
	for (int i = 1; i <= n; i++)
	{
		if (is_done[i] == 0 && link[v][i] == 1)
			DFS(n, i);
	}
	return ;
}

int main()
{
	int n, m;
	int a, b;
	int ans = 0;

	scanf("%d", &n);
	scanf("%d", &m);
	while (m-- > 0)
	{
		scanf("%d %d", &a, &b);
		link[a][b] = 1;
		link[b][a] = 1;
	}
	DFS(n, 1);
	for (int i = 1; i <= n; i++)
		ans += is_done[i] == 1 ? 1 : 0;
	printf("%d", ans - 1);
	return 0;
}
