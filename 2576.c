#include <stdio.h>

int main()
{
	int sum = 0;
	int a;
	int min = 101;

	for (int i = 0; i < 7; i++)
	{
		scanf("%d", &a);
		if (a % 2 == 1)
		{
			sum += a;
			if (min > a)
				min = a;
		}
	}
	if (min == 101)
	{
		printf("-1");
		return 0;
	}
	printf("%d\n%d", sum, min);
	return 0;
}

