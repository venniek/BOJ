#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
	int n1 = *(int *)a;
	int n2 = *(int *)b;

	if (n1 == n2)
		return 0;
	return (n1 > n2 ? 1 : -1);
}

int ft_max(int a, int b)
{
	return (a > b ? a : b);
}

int main()
{
	int n;
	double sum = 0;
	int san, mid, max, ran;
	int *num;
	int nummax[8001] = { 0 };

	scanf("%d", &n);
	num = (int *)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &num[i]);
		sum += num[i];
		nummax[num[i] + 4000]++;
	}
	if (sum / n >= 0)
		san = (int)(sum / n + 0.5);
	else
		san = (int)(sum / n - 0.5);
	qsort(num, n, sizeof(int), cmp);
	mid = num[n / 2];
	max = 0;
	for (int i = 1; i < 8001; i++)
		if (nummax[i] > nummax[max]) max = i;
	int tmp[2] = { 0 };
	int k = 0;
	for (int i = 0; i < 8001; i++)
	{
		if (nummax[i] == nummax[max])
			tmp[k++] = i;
		if (k == 2)
			break;
	}
	max = ft_max(tmp[0], tmp[1]) - 4000;
	ran = num[n - 1] - num[0];
	printf("%d\n%d\n%d\n%d", san, mid, max, ran);
	return 0;
}
