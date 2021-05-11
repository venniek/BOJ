#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;
	int maxi = 0;
	int *num;
	int *max;
	int *ans;

	scanf("%d", &n);
	num = (int *)malloc(sizeof(int) * n);
	max = (int *)malloc(sizeof(int) * n);
	ans = (int *)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
		scanf("%d", &num[i]);
	for (int i = 0; i < n; i++)
		ans[i] = -1;
	max[maxi++] = num[n - 1];
	for (int i = n - 2; i >= 0; i--)
	{
		if (max[maxi - 1] > num[i])
		{
			ans[i] = max[maxi - 1];
			max[maxi++] = num[i];
		}
		else
		{
			while (maxi > 0 && max[maxi - 1] <= num[i])
				maxi--;
			if (maxi == 0)
				ans[i] = -1;
			else
				ans[i] = max[maxi - 1];
			max[maxi++] = num[i];
		}
	}
	for (int i = 0; i < n; i++)
		printf("%d ", ans[i]);
	return 0;
}
