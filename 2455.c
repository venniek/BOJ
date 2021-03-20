#include <stdio.h>

int main()
{
	int out, in;
	int max = 0;
	int total = 0;

	for (int i = 0; i < 4; i++)
	{
		scanf("%d %d", &out, &in);
		total = total - out + in;
		max = total > max ? total : max;
	}
	printf("%d", max);
	return 0;
}
