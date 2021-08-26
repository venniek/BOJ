#include <stdio.h>

void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int main()
{
	int num[1000];
	int n;

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &num[i]);
	for (int i = 0; i < n - 1; i++)
		for (int k = 1; k < n - i ; k++)
			if (num[i] > num[i + k])
				swap(&num[i], &num[i + k]);
	for (int i = 0; i < n - 1; i++)
		printf("%d\n", num[i]);
	printf("%d", num[n - 1]);
	return 0;
}
