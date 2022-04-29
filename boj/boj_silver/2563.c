#include <stdio.h>

int main()
{
	int pan[100][100] = { 0, };
	int n;
	int x, y;
	int ans = 0;

	scanf("%d", &n);
	while (n-- > 0)
	{
		scanf("%d %d", &x, &y);
		for (int i = x; i < x + 10; i++)
		{
			for (int k = y; k < y + 10; k++)
				pan[i][k] = 1;
		}
	}
	for (int i = 0; i < 100; i++)
	{
		for (int k = 0; k < 100; k++)
		{
			if (pan[i][k] == 1)
				ans++;
		}
	}
	printf("%d", ans);
}
