#include <stdio.h>

typedef struct s_max
{
	int max1;
	int max2;
} t_max;

int is_max(int a, int b)
{
	return (a > b ? a : b);
}

int main()
{
	int n;
	int score[301] = { 0 };
	t_max m[301];

	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &score[i]);
	m[1].max1 = score[1];
	m[1].max2 = score[1];
	m[2].max1 = score[2];
	m[2].max2 = score[1] + score[2];
	for (int i = 3; i <= n; i++)
	{
		m[i].max1 = is_max(m[i - 2].max1, m[i - 2].max2) + score[i];
		m[i].max2 = m[i - 1].max1 + score[i];
	}
	printf("%d", is_max(m[n].max1, m[n].max2));
	return 0;
}
