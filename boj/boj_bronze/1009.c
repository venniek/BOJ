#include <stdio.h>

int make_ans(int a, int b)
{
	int ans = 1;

	if (a == 0)
		return (10);
	if (a == 1 || a == 5 || a == 6)
		return (a);
	if (b == 0)
		b = 4;
	while (b-- > 0) ans = ans * a % 10;
	return (ans);
}

int main()
{
	int n;
	int a, b;
	int ans;

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &a, &b);
		printf("%d\n", make_ans(a % 10, b % 4));
	}
	return 0;
}
