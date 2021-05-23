#include <stdio.h>
#include <stdlib.h>

int max(int a, int b)
{
	return (a > b ? a : b);
}

int cmp(const void *a, const void *b)
{
	int num1 = *(int *)a;
	int num2 = *(int *)b;

	if (num1 > num2)
		return -1;
	if (num1 < num2)
		return 1;
	return 0;
}

int main()
{
	int n;
	int *wei;
	int ans = 0;

	scanf("%d", &n);
	wei = (int *)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
		scanf("%d", &wei[i]);
	qsort(wei, n, sizeof(int), cmp);
	for (int i = 0; i < n; i++)
		ans = max(ans, wei[i] * (i + 1));
	printf("%d", ans);
	return 0;
}
