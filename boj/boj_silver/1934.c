#include <stdio.h>

int min(int a, int b)
{
	int ans;

	ans = a > b ? b : a;
	while (!(a % ans == 0 && b % ans == 0))
		ans--;
	return (a * b / ans);
}

int main()
{
	int t;
	int a, b;

	scanf("%d", &t);
	while (t-- > 0)
	{
		scanf("%d %d", &a, &b);
		printf("%d\n", min(a, b));
	}
	return 0;
}
