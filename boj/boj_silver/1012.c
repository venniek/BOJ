#include <stdio.h>

typedef struct s_que {
	int x;
	int y;
}	t_que;

t_que que[2500];
int map[52][52];
int is_done[52][52];
int m, n;

void clear_map() {
	for (int i = 0; i < 52; i++) {
		for (int k = 0; k < 52; k++)  {
			map[i][k] = 0;
			is_done[i][k] = 1;
		}
	}
}

void is_que(int x, int y, int *end) {
	if (map[y][x] == 1 && is_done[y][x] == 0) {
		que[*end].x = x;
		que[*end].y = y;
		is_done[y][x] = 1;
		(*end)++;
	}
}

int find_start(int *stx, int *sty) {
	for (int i = 1; i <= n; i++) {
		for (int k = 1; k <= m; k++) {
			if (map[i][k] == 1 && is_done[i][k] == 0) {
				*stx = k;
				*sty = i;
				is_done[i][k] = 1;
				return (1);
			}
		}
	}
	return (0);
}

int bfs() {
	int start;
	int end;
	int popx, popy;
	int ret = 0;
	int stx, sty;

	while (1)
	{
		start = 0;
		end = 0;
		if (find_start(&stx, &sty) == 0)
			return (ret);
		que[end].x = stx;
		que[end++].y = sty;
		while (start < end)
		{
			popx = que[start].x;
			popy = que[start++].y;
			is_que(popx, popy + 1, &end);
			is_que(popx, popy - 1, &end);
			is_que(popx + 1, popy, &end);
			is_que(popx - 1, popy, &end);
		}
		ret++;
	}
}

int main()
{
	int t;
	int x, y;
	int k;

	scanf("%d", &t);
	while (t-- > 0)
	{
		clear_map();
		scanf("%d %d %d", &m, &n, &k);
		while (k-- > 0)
		{
			scanf("%d %d", &x, &y);
			map[y + 1][x + 1] = 1;
			is_done[y + 1][x + 1] = 0;
		}
		printf("%d\n", bfs());
	}
	return 0;
}

