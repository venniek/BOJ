#include <stdio.h>
#include <stdlib.h>

typedef struct s_name
{
	int age;
	char name[101];
} t_name;

int main()
{
	int n;
	t_name *ppl;

	scanf("%d", &n);
	ppl = (t_name *)malloc(sizeof(t_name) * n);
	for (int i = 0; i < n; i++)
		scanf("%d %s", &ppl[i].age, ppl[i].name);
	for (int i = 1; i <= 200; i++)
	{
		for (int k = 0; k < n; k++)
		{
			if (ppl[k].age == i)
				printf("%d %s\n", ppl[k].age, ppl[k].name);
		}
	}
	return 0;
}
