#include <stdio.h>
#include <stdlib.h>

typedef struct s_list {
	int x;
	int y;
	int r;
} person;

int make_rank(person *p, int i, int n)
{
	int ret = 0;

	for (int k = 0; k < n; k++)
	{
		if (p[i].x < p[k].x && p[i].y < p[k].y)
			ret++;
	}
	return (ret + 1);
}

int main()
{
	int n;
	person *p;

	scanf("%d", &n);
	if (!(p = (person *)malloc(sizeof(person) * n)))
		return (-1);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &p[i].x, &p[i].y);
	for (int i = 0; i < n; i++)
		p[i].r = make_rank(p, i, n);
	for (int i = 0; i < n - 1; i++)
		printf("%d ", p[i].r);
	printf("%d", p[n - 1].r);
	free(p);
	return 0;
}
