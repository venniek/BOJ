#include <stdio.h>
#include <stdlib.h>

int make_i(int a, int b)
{
	return (a * (a + 1) / 2 + b);
}

int ft_max(int a, int b)
{
	return (a > b ? a : b);
}

int main()
{
	int n;
	int *num;
	int *ans;

	scanf("%d", &n);
	num = (int *)malloc(sizeof(int) * (n + 1) * n / 2);
	ans = (int *)malloc(sizeof(int) * (n + 1) * n / 2);
	for (int i = 0; i < n * (n + 1) / 2; i++)
		scanf("%d", &num[i]);
	for (int i = 0; i < n * (n + 1) / 2; i++)
		ans[i] = -1;
	ans[0] = num[0];		
	for (int a = 1; a < n; a++)
	{
		for (int b = 0; b <= a; b++)
		{
				if (b == 0)
					ans[make_i(a, b)] = ans[make_i(a - 1, b)] + num[make_i(a, b)];
				else if (b == a)
					ans[make_i(a, b)] = ans[make_i(a - 1, b - 1)] + num[make_i(a, b)];
				else
					ans[make_i(a, b)] = ft_max(ans[make_i(a - 1, b - 1)], ans[make_i(a - 1, b)]) + num[make_i(a, b)];
		}
	}
	int max = ans[make_i(n - 1, 0)];
	for (int a = 1; a < n; a++)
		max = ft_max(ans[make_i(n - 1, a)], max);
	printf("%d", max);
	return 0;
}
