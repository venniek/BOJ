#include <stdio.h>

int main()
{
	int t;
	int a;
	int b;

	scanf("%d", &t);
	while (t-- > 0)
	{
		scanf("%d, %d", &a, &b);
		printf("%d\n", a + b);
	}
	return 0;
}
