#include <stdio.h>

int bridge(int n, int m)
{
	int ans = 0;

	if (n == 1)
		return (m);
	if (n == m)
		return (1);
	if (n > m / 2)
		return (bridge(m - n, m));
	for (int i = 1; i < m; i++)
		ans += bridge(n - 1, i);
	return (ans);
}

int main()
{
	int t;
	int n, m;

	scanf("%d", &t);
	while (t-- > 0)
	{
		scanf("%d %d", &n, &m);
		printf("%d\n", bridge(n, m));
	}
	return 0;
}
