#include <stdio.h>

int main()
{
	int x;
	int ans = 0;

	scanf("%d", &x);
	while (x > 0)
	{
		ans += x % 2;
		x /= 2;
	}
	printf("%d", ans);
	return 0;
}
