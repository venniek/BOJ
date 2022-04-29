#include <stdio.h>

int ans(int k)
{
	int ret;

	ret = k;
	while (k > 0)
	{
		ret += k % 10;
		k /= 10;
	}
	return (ret);
}

int main()
{
	int n;
	int k = 1;
	int t = 0;

	scanf("%d", &n);
	while (k < n)
	{
		if (ans(k) == n)
		{
			t = k;
			break;
		}
		k++;
	}
	printf("%d", t);
	return (0);
}
