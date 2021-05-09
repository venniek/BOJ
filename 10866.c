#include <stdio.h>
#include <string.h>

int main()
{
	int n;
	int deq[10000] = { 0 };
	char order[11];
	int start = 0;
	int end = 0;

	scanf("%d", &n);
	while (n-- > 0)
	{
		order[0] = '\0';
		scanf("%s", order);
		if (strcmp(order, "push_back") == 0)
		{
			if (start == 0)
			{
				for (int i = end; i > start; i--)
					deq[i] = deq[i - 1];
				scanf("%d", &deq[0]);
				end++;
			}
			else
				scanf("%d", &deq[--start]);
		}
		else if (strcmp(order, "push_front") == 0)
			scanf("%d", &deq[end++]);
		else if (strcmp(order, "pop_back") == 0)
			printf("%d\n", start == end ? -1 : deq[start++]);
		else if (strcmp(order, "pop_front") == 0)
			printf("%d\n", start == end ? -1 : deq[--end]);
		else if (strcmp(order, "size") == 0)
			printf("%d\n", end - start);
		else if (strcmp(order, "empty") == 0)
			printf("%d\n", start == end ? 1 : 0);
		else if (strcmp(order, "back") == 0)
			printf("%d\n", start == end ? -1 : deq[start]);
		else if (strcmp(order, "front") == 0)
			printf("%d\n", start == end ? -1 : deq[end - 1]);
	}
	return 0;
}
