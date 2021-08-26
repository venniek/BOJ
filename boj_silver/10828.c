#include <stdio.h>
#include <string.h>

int num[10000] = { -1 };
int i = 0;

void make_stack(char *order)
{
	if (order[0] == 'p')
	{
		if (i == 0)
			printf("-1\n");
		else
		{
			printf("%d\n", num[--i]);
			num[i] = -1;
		}
	}
	else if (order[0] == 't')
	{
		if (i == 0)
			printf("-1\n");
		else
			printf("%d\n", num[i - 1]);
	}
	else if (order[0] == 's')
		printf("%d\n", i);
	else if (order[0] == 'e')
		printf("%d\n", i == 0 ? 1 : 0);
	return ;
}


int main()
{
	int n;
	char order[6];
	int x;

	scanf("%d", &n);
	while (n-- > 0)
	{
		scanf("%s", order);
		if (order[3] == 'h')
		{
			scanf("%d", &x);
			num[i++] = x;
		}
		else
			make_stack(order);
		for (int k = 0; k < 5; k++) 
			order[k] = '\0';
	}
	return (0);
}
