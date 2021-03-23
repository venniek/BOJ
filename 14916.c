#include <stdio.h>

int main()
{
	int n;
	int ans = 0;
	
	scanf("%d", &n);
	if (n == 1 || n == 3)
		ans = -1;
	else if (n % 5 == 0)
		ans = n / 5;
	else if (n % 5 % 2 == 0)
		ans += n / 5 + n % 5 / 2;
	else
		ans += n / 5 - 1 + (n -  (n / 5 - 1) * 5) / 2;
	printf("%d", ans);
	return 0;
}
