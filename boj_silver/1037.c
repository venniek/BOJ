#include <stdio.h>
#include <stdlib.h>

void sort(int *a, int n)
{
	int tmp;

	for (int i = 0; i < n - 1; i++)
	{
		for (int k = 1; k < n - i; k++)
		{
			if (a[i] > a[i + k])
			{
				tmp = a[i];
				a[i] = a[i + k];
				a[i + k] = tmp;
			}
		}
	}
}


int main()
{
	int n;
	int *a;

	scanf("%d", &n);
	a = (int *)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, n);
	printf("%d", a[0] * a[n - 1]);
	free(a);
	a = 0;
	return (0);
}
