#include <stdio.h>
#include <stdlib.h>

int cpr(const void *a, const void *b)
{
	int na = *(int *)a;
	int nb = *(int *)b;

	if (na > nb)
		return 1;
	if (na < nb)
		return -1;
	return 0;
}

int main()
{
	int n;
	int num[1000000];

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &num[i]);
	qsort(num, n, sizeof(int), cpr);
	for (int i = 0;i < n; i++)
		printf("%d\n", num[i]);
	return 0;
}
