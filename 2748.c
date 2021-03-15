#include <stdio.h>

long long fbnc2(int n)
{
	long long a = 0;
	long long b = 1;
	long long ans;

	if (n == 0)
		return (a);
	if (n == 1)
		return (b);
	while (n-- > 1)
	{
		ans = a + b;
		long long tmp = b;
		b = ans;
		a = tmp;
	}
	return (ans);
}

int main()
{
	int n;
	
	scanf("%d", &n);
	printf("%lld", fbnc2(n));
	return 0;
}
