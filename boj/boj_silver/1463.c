#include <stdio.h>
#include <stdlib.h>

int ft_min(int a, int b)
{
	return (a > b ? b : a);
}

int main()
{
	int n;
	int *ans;

	scanf("%d", &n);
	ans = (int *)malloc(sizeof(int) * (n + 1));
	ans[0] = 0;
	ans[1] = 0;
	ans[2] = 1;
	ans[3] = 1;
	for (int i = 4; i <= n; i++)
	{
		int min = ans[i - 1] + 1;
		if (i % 2 == 0)
			min = ft_min(min, ans[i / 2] + 1);
		if (i % 3 == 0)
			min = ft_min(min, ans[i / 3] + 1);
		ans[i] = min;
	}
	printf("%d", ans[n]);
	return 0;
}
