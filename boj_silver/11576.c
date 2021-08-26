#include <stdio.h>
#include <math.h>

int main()
{
	int a, b;
	int m;
	int num[25];
	int sum = 0;
	int ans[20];

	scanf("%d %d", &a, &b);
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &num[i]);
		sum += num[i] * pow(a, m - i - 1);
	}
	int i = 0;
	while (sum > 0)
	{
		ans[i] = sum % b;
		sum /= b;
		i++;
	}
	while (i-- > 0)
		printf("%d ", ans[i]);
	return 0;
}
