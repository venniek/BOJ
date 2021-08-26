#include <stdio.h>

int is_max(int n, int m)
{
	return (n > m * 2 ? m : n / 2);
}

int main()
{
	int n, m, k;
	int max = 0;
	int num;

	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i <= k; i++)
	{
		if (max < (num = is_max(n - i, m - (k - i))))
			max = num;
	}
	printf("%d", max);
	return 0;
}
