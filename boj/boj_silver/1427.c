#include <stdio.h>
#include <string.h>

int main()
{
	int n;
	int num[10] = { 0 };

	scanf("%d", &n);
	while (n > 0)
	{
		num[n % 10]++;
		n /= 10;
	}
	for (int i = 9; i >= 0; i--)
	{
		while (num[i] > 0)
		{
			printf("%d", i);
			num[i]--;
		}
	}
	return 0;
}

