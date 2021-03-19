#include <stdio.h>

int facto(int a, int b)
{
	int ans = 1;

	for (int i = b; i <= a; i++)
		ans *= i;
	return (ans);
}

int main()
{
	int n, k;
	int ans;

	scanf("%d %d", &n, &k);
	if (n == k)
		ans = 1;
	else
		ans = facto(n, k + 1) / facto(n - k, 1);
	printf("%d", ans);
	return 0;
}
