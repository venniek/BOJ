#include <stdio.h>

int min(int a, int b)
{
	return (a > b ? b : a);
}

int main()
{
	int l, p, v;
	int ans;
	int i = 1;

	while (1)
	{
		scanf("%d %d %d", &l, &p, &v);
		if (l == 0)
			break;
		ans = v / p * l + min(v % p, l);
		printf("Case %d: %d\n", i, ans);
		i++;
	}
	return 0;
}
