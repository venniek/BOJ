#include <stdio.h>
#include <string.h>

int main()
{
	char order[7];
	int m;
	int x[20] = { 0 };

	scanf("%d", &m);
	while (m-- > 0)
	{
		scanf("%s", order);
		if (strcmp(order, "all") == 0)
		{
			for (int i = 0; i < 20; i++)
				x[i] = 1;
		}
		else if (strcmp(order, "empty") == 0)
		{
			for (int i = 0; i < 20; i++)
				x[i] = 0;
		}
		else
		{
			int d;
			scanf("%d", &d);
			if (strcmp(order, "add") == 0)
				x[d - 1] = 1;
			else if (strcmp(order, "remove") == 0)
				x[d - 1] = 0;
			else if (strcmp(order, "check") == 0)
				printf("%d\n", x[d - 1] == 1? 1 : 0);
			else if (strcmp(order, "toggle") == 0)
				x[d - 1] = x[d - 1] == 1 ? 0 : 1;
		}
	}
	return (0);
}
