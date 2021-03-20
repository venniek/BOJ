#include <stdio.h>

int is_int(int i, int n)
{
	int ret = 0;
	
	while (i % n == 0)
	{
		ret++;
		i /= n;
	}
	return (ret);
}

int main()
{
	int n;
	int two_cnt = 0;
	int five_cnt = 0;

	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		two_cnt += is_int(i, 2);
		five_cnt += is_int(i, 5);
	}
	printf("%d", two_cnt < five_cnt ? two_cnt : five_cnt);
	return (0);
}
