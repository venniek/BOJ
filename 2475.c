#include <stdio.h>

int main()
{
	int a[5];
	int ans = 0;

	for (int i = 0; i < 5; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < 5; i++)
		ans += a[i] * a[i];
	printf("%d", ans % 10);
	return 0;
}
