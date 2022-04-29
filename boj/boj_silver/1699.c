#include <stdio.h>

int main()
{
	int ans[100001] = { 0 };
	int n;

	scanf("%d", &n);
	for (int i = 1; i <= n / i; i++)
		ans[i * i] = 1;
	ans[2] = 2;
	for (int i = 3; i <= n; i++)
	{
		if (ans[i] == 1)
			continue;
		ans[i] = ans[i - 1] + 1;
		for (int k = 2; k <= i / 2; k++)
		{
			int min = ans[k] + ans[i - k];
			if (ans[i] > min)
				ans[i] = min;
		}
	}
	printf("%d", ans[n]);
	return 0;
}

