#include <stdio.h>

int main()
{
	int n;
	int num[2002] = { 0 };
	int tmp;

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &tmp);
		num[tmp + 1000]++;
	}
	int k = 0;
	for (int i = 0; i < 2002; i++)
	{
		if (num[i] > 0)
			printf("%d ", i - 1000);
		k += num[i];
		if (k == n)
			break;
	}
	return 0;
}
