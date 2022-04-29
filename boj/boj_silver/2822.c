#include <stdio.h>

typedef struct s_num
{
	int num;
	int rank;
} t_num;

int main()
{
	t_num s[8];
	int sum = 0;

	for (int i = 0; i < 8; i++)
	{
		scanf("%d", &s[i].num);
		s[i].rank = i;
	}
	for (int i = 0; i < 5; i++)
	{
		int max = i;
		for (int k = i + 1; k < 8; k++)
		{
			if (s[max].num < s[k].num)
				max = k;
		}
		if (i != max)
		{
			int tmp = s[i].num;
			s[i].num = s[max].num;
			s[max].num = tmp;
			tmp = s[i].rank;
			s[i].rank = s[max].rank;
			s[max].rank = tmp;
		}
		sum += s[i].num;
	}
	for (int i = 0; i < 4; i++)
	{
		int min = i;
		for (int k = i + 1; k < 5; k++)
		{
			if (s[min].rank > s[k].rank)
				min = k;
		}
		if (i != min)
		{
			int tmp = s[i].rank;
			s[i].rank = s[min].rank;
			s[min].rank = tmp;
		}
	}
	printf("%d\n", sum);
	for (int i = 0; i < 5; i++)
		printf("%d ", s[i].rank + 1);
	return 0;
}
