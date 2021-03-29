#include <stdio.h>

int main()
{
	int k;
	int n;
	int num[100000] = { -1 };
	int sum = 0;
	int i = 0;

	scanf("%d", &k);
	for (int j = 0; j < k; j++)
	{
		scanf("%d", &n);
		if (n != 0)
			num[i++] = n;
		else
			num[--i] = -1;
	}
	for (int j = 0; j < i; j++)
		sum += num[j];
	printf("%d", sum);
	return 0;
}
