#include <stdio.h>

int main()
{
	int a;
	int b = -1;
	int n;
	int ans;

	scanf("%d", &n);
	
	a = n / 5;
	while (a >= 0)
	{
		if ((n - a * 5) % 3 == 0)
		{
			b = (n - a * 5) / 3;
			ans = a + b;
			break;
		}
		else
			a--;
	}
	if (b == -1)
		printf("-1");
	else
		printf("%d", ans);

	return 0;
}
