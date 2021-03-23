#include <stdio.h>
#include <math.h>

int numlen(int a)
{
	int len = 0;

	while (a > 0)
	{
		len++;
		a /= 10;
	}
	return (len);
}

int main()
{
	int t;
	unsigned int n;
	int ban;
	int maxban;
	int len;
	
	scanf("%d", &t);
	while (t-- > 0)
	{
		scanf("%d", &n);
		if (n == 1000000000)
			printf("8999999999000000000");
		else
		{
			len = numlen(n);
			maxban = pow(10, len) / 2;
			ban = maxban * 2 - 1;
			if (n >= maxban)
				n = maxban;
			printf("%llu\n", (unsigned long long)n * (ban - n));
		}
	}
	return 0;
}
