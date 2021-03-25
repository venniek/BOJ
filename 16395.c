#include <stdio.h>

int pas[30][30] = { 0, };

int pascal(int n, int k)
{
	if (pas[n][k] != 0)
		return (pas[n][k]);
	if (k == 0)
		pas[n][k] = 1;
	else if (k == n)
		pas[n][k] = 1;
	else if (k > n / 2)
		pas[n][k] = pascal(n, n - k);
	else
		pas[n][k] = pascal(n - 1, k) + pascal(n - 1, k - 1);
	return (pas[n][k]);
}

int main()
{
	int n, k;

	scanf("%d %d", &n, &k);
	printf("%d", pascal(n - 1, k - 1));
	return 0;
}
