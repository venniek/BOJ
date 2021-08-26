#include <stdio.h>
#include <math.h>

int main()
{
	int t;
	int n;

	scanf("%d", &t);
	while (t-- > 0)
	{
		scanf("%d", &n);
		printf("%d\n", (int)sqrt(n));
	}
	return 0;
}
