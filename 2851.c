#include <stdio.h>
#include <stdlib.h>

int make_ans(int a, int b)
{
	int minus;

	minus = abs(100 - a) - abs(100 - b);
	if (minus > 0)
		return (b);
	else if (minus == 0)
		return (a < b ? b : a);
	else
		return (a);
}

int main()
{
	int sum;
	int n[10];
	int max = 0;

	for (int i = 0; i < 10; i++)
		scanf("%d", &n[i]);
	for (int i = 0; i < 10; i++)
	{
		sum = 0;
		for (int k = 0; k < i + 1; k++)
			sum += n[k];
		max = make_ans(max, sum);
	}

	printf("%d", max);
	return 0;
}	
