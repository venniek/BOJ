#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, b, c;
	int *a;
	int bu;
	long long total = 0;

	scanf("%d", &n);
	a = (int *)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	scanf("%d %d", &b, &c);
	for (int i = 0; i < n; i++)
	{
		bu = 0;
		if (a[i] <= b)
			bu = 0;
		else
		{
			a[i] -= b;
			bu = a[i] % c == 0 ? a[i] / c : a[i] / c + 1;
		}
		total += bu + 1;
	}
	printf("%lld", total);
	free(a);
	a = 0;
	return 0;
}
