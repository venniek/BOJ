#include <stdio.h>

int main()
{
	int yen[6] = { 500, 100, 50, 10, 5, 1 };
	int ans = 0;
	int money;

	scanf("%d", &money);
	money = 1000 - money;
	for (int i = 0; i < 6; i++)
	{
		ans += money / yen[i];
		money %= yen[i];
	}
	printf("%d", ans);
	return 0;
}
