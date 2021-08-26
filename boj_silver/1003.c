#include <stdio.h>

int fibo(int n)
{
	int a = 1;
	int b = 1;

	if (n == 0)
		return (0);
	if (n == 1)
		return (a);
	if (n == 2)
		return (b);
	for (int i = 0; i < n - 2; i++)
	{
		int tmp = b;
		b = a + b;
		a = tmp;
	}
	return (b);
}

int main()
{
	int t;
	int n;

	scanf("%d", &t);
	while (t-- > 0)
	{
		scanf("%d", &n);
		printf("%d %d\n", fibo(n - 1), fibo(n));
	}
	return 0;
}
