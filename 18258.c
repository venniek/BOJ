#include <stdio.h>
#include <string.h>

int main()
{
	int que[2000000] = { 0 };
	int n;
	int start = 0;
	int end = 0;
	char order[6];

	scanf("%d", &n);
	
	while (n-- > 0)
	{
		order[0] = '\0';
		scanf("%s", order);
		if (strcmp(order, "push") == 0)
			scanf("%d", &que[end++]);
		else if (strcmp(order, "pop") == 0)
			printf("%d\n", start == end ? -1 : que[start++]);
		else if (strcmp(order, "size") == 0)
			printf("%d\n", end - start);
		else if (strcmp(order, "empty") == 0)
			printf("%d\n", end == start ? 1 : 0);
		else if (strcmp(order, "front") == 0)
			printf("%d\n", end == start ? -1 : que[start]);
		else if (strcmp(order, "back") == 0)
			printf("%d\n", end == start ? -1 : que[end - 1]);
	}
	return 0;
}

