#include <stdio.h>

int main()
{
	int n;
	int a[50];

	scanf("%d", &n);
	scanf("%d", &a[0]);
	int min = a[0];
	int max = a[0];
	for (int i = 1; i < n; i++)
	{
		scanf("%d", &a[i]);
		if (a[i] < min)
			min = a[i];
		if (a[i] > max)
			max = a[i];
	}
	printf("%d", min * max);
	return (0);
}
