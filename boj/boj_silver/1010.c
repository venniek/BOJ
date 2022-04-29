#include <stdio.h>

int b[30][30] = { 0, };

int bridge(int n, int m)
{
	if (b[m][n])
		return (b[m][n]);
	if (n == 1)
		b[m][n] = m;
	else if (n == m)
		b[m][n] = 1;
	else if	(n > m / 2)
		b[m][n] = b[m][m - n];
	else
		b[m][n] = bridge(n - 1, m - 1) + bridge(n, m - 1);
	return (b[m][n]);
}

int main()
{
	int t;
	int n, m;
	int **b;

	scanf("%d", &t);
	while (t-- > 0)
	{
		scanf("%d %d", &n, &m);
		printf("%d\n", bridge(n, m));
	}
	return 0;
}
