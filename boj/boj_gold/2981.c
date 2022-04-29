#include <stdio.h>
#include <stdlib.h>

int make_gcd(int a, int b)
{
	if (a == b)
		return (a);

	int min = a > b ? b : a;
	int max = a > b ? a : b;

	if (a % (max - min) == 0 && b % (max - min) == 0)
		return (max - min);
	else
		return (make_gcd(min, max - min));
}

int main()
{
	int n;
	int *num;
	int *minus;
	int gcd;

	scanf("%d", &n);
	num = (int *)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
		scanf("%d", &num[i]);
	minus = (int *)malloc(sizeof(int) * (n - 1));
	for (int i = 0; i < n - 1; i++)
		minus[i] = abs(num[i] - num[i + 1]);
	gcd = minus[0];
	for (int i = 1; i < n - 1; i++)
		gcd = make_gcd(gcd, minus[i]);
	for (int i = 2; i <= gcd / 2; i++)
		if (gcd % i == 0) printf("%d ", i);
	printf("%d", gcd);
	return 0;
}
