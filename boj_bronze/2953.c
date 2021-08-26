#include <stdio.h>

int main()
{
	int score[5] = { 0 };
	int a;
	int max = 0;
	int idx = 0;

	for (int i = 0; i < 5; i++)
	{
		for (int k = 0; k < 4; k++)
		{
			scanf("%d", &a);
			score[i] += a;
		}
		if (score[i] > max)
		{
			max = score[i];
			idx = i;
		}
	}
	printf("%d %d", idx + 1, max);
	return (0);
}
