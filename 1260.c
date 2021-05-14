#include <stdio.h>

int is_done[1001] = { 0 };
int link[1001][1001] = { 0, };
int que[1001];

void DFS(int n, int v)
{
	is_done[v] = 1;
	printf("%d ", v);
	for (int i = 1; i <= n; i++)
	{
		if (is_done[i] == 0 && link[v][i] == 1)
			DFS(n, i);
	}
	return ;
}

void BFS(int n, int v)
{
	int start = 0;
	int end = 0;
	int pop;

	is_done[v] = 1;
	printf("%d ", v);
	que[end++] = v;
	while (start < end)
	{
		pop = que[start++];
		for (int i = 1; i <= n; i++)
		{
			if (link[pop][i] == 1 && is_done[i] == 0)
			{
				que[end++] = i;
				is_done[i] = 1;
				printf("%d ", i);
			}
		}
	}
	return ;
}


int main()
{
	int n, m, v;
	int a, b;

	scanf("%d %d %d", &n, &m, &v);
	while (m-- > 0)
	{
		scanf("%d %d", &a, &b);
		link[a][b] = 1;
		link[b][a] = 1;
	}
	DFS(n, v);
	printf("\n");
	for (int i = 1; i <= n; i++)
		is_done[i] = 0;
	BFS(n, v);
	return 0;
}
