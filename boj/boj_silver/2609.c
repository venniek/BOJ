#include <stdio.h>

int main()
{
	int a;
	int b;
	int max;
	int min;

	scanf("%d %d", &a, &b);
	max = a > b ? b : a;
	while (!(a % max == 0 && b % max == 0))
		max--;
	min = a * b / max;
	printf("%d\n%d", max, min);
	return 0;
}
