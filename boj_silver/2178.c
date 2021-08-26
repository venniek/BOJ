#include <stdio.h>

typedef struct s_que
{
	int x;
	int y;
}	t_que;

t_que que[10000];
int map[102][102] = { 0, };
int is_done[102][102] = { 0, };
int lvl[10000] = { 0 };
int min = 1;
int n, m;

void is_que(int x, int y, int *end, int i)
{
	if (map[x][y] == 1 && is_done[x][y] == 0)
	{
		que[*end].x = x;
		que[*end].y = y;
		is_done[x][y] = 1;
		(*end)++;
		lvl[i + 1]++;
	}
}

void find_ans()
{
	int start = 0;
	int end = 0;
	int popx, popy;
	int i = 0;

	is_done[1][1] = 1;
	que[end].x = 1;
	que[end++].y = 1;
	lvl[i] = 1;
	while (1)
	{
		popx = que[start].x;
		popy = que[start++].y;
		lvl[i]--;
		if (popx == n && popy == m)
			return ;
		is_que(popx, popy + 1, &end, i);
		is_que(popx, popy - 1, &end, i);
		is_que(popx + 1, popy, &end, i);
		is_que(popx - 1, popy, &end, i);
		if (lvl[i] == 0)
		{
			i++;
			min++;
		}
	}
}

int main()
{
	char num[101];

	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		num[0] = '\0';
		scanf("%s", num);
		for (int k  = 0; k < m; k++)
			map[i][k + 1] = num[k] - '0';
	}
	find_ans();
	printf("%d", min);
	return 0;
}

