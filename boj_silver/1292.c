#include <stdio.h>

int suyul(int n)
{
	int i = 1;

	while (!((i - 1) * i / 2 < n && n <= i * (i + 1) / 2))
		i++;
	return (i);
}

int sum_ab(int a, int b)
{
	int sum = 0;

	for (int i = a; i <= b; i++)
		sum += suyul(i);
	return (sum);
}

int main()
{
	int a, b;

	scanf("%d %d", &a, &b);
	printf("%d", sum_ab(a, b));
	return 0;
}
