#include <stdio.h>

int main()
{
	int num;
	int i = 2;

	scanf("%d", &num);
	while (1)
	{
		if (num % i == 0)
		{
			num /= i;
			printf("%d\n", i);
		}
		else
			i++;
		if (num == 1)
			break;
	}
	return 0;
}
