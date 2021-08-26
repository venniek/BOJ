#include <stdio.h>

int main()
{
	int n;
	int ans = 0;
	int a;

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a);
		ans += a == 1? 1 : -1;	
	}
	if (ans > 0)
		printf("Junhee is cute!");
	else
		printf("Junhee is not cute!");
	return 0;
}
