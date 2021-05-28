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

int main()
{
	int n, k;
	int *num;

	scanf("%d %d", &n, &k);
	num = (int *)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
		scanf("%d", &num[i]);
	qsort(num, n, sizeof(int), cmp);
	printf("%d", num[k - 1]);
	return 0;
}
