#include <stdio.h>

int main()
{
	int n;
	int num[10] = { 0 };

	scanf("%d", &n);
	if (n == 0)
	{
		printf("1");
		return 0;
	}
	while (n > 0)
	{
		num[n % 10]++;
		n /= 10;
	}
	if ((num[6] + num[9]) % 2 == 0)
	{
		num[6] = (num[6] + num[9]) / 2;
		num[9] = num[6];
	}
	else
	{
		num[6] = (num[6] + num[9]) / 2;
		num[9] = num[6] + 1;
	}
	int max = 0;
	for (int i = 0; i < 10; i++)
	{
		if (max < num[i])
			max = num[i];
	}
	printf("%d", max);
	return 0;
}
