#include <stdio.h>

int ans(int a, int b)
{
	int re[4];

	re[0] = a;
	for (int i = 1; i < 4; i++)
		re[i] = re[i - 1] * a % 10;
	if (b == 0)
		b = 4;
	return (re[b - 1]);
}

int make_ans(int a, int b)
{
	if (a == 0)
		return (10);
	if (a == 1 || a == 5 || a == 6)
		return (a);
	else
		return (ans(a, b));
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
