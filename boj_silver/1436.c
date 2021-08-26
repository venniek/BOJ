#include <stdio.h>

int is_threesix(int n)
{
	int k = 0;

	while (n > 0)
	{
		if (n % 10 == 6)
			k = k * 10 + 6;
		else
			k = 0;
		if (k == 666)
			return (1);
		n /= 10;
	}
	return (0);
}

int main()
{
	int n;
	int num = 666;

	scanf("%d", &n);
	while (n > 0)
	{
		if (is_threesix(num) == 1)
			n--;
		num++;
	}
	printf("%d", num - 1);
	return (0);
}
