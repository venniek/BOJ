#include <stdio.h>
#include <stdlib.h>

long long pado(int n)
{
	long long ans[6];
	int i = 0;
	
	ans[0] = 1;
	ans[1] = 1;
	ans[2] = 1;
	ans[3] = 2;
	ans[4] = 2;
	ans[5] = 3;
	if (n < 6)
		return (ans[n - 1]);
	while (i++ < n - 6)
	{
		for (int k = 0; k < 5; k++)
			ans[k] = ans[k + 1];
		ans[5] = ans[4] + ans[0];
	}
	return (ans[5]);
}

int main()
{
	int t;
	int n;

	scanf("%d", &t);
	while (t-- > 0)
	{
		scanf("%d", &n);
		printf("%lld\n", pado(n));
	}
	return 0;
}
