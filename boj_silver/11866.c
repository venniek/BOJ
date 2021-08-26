#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, k;
	int *peo;
	int *kill;

	scanf("%d %d", &n, &k);
	peo = (int *)malloc(sizeof(int) * n);
	kill = (int *)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
		peo[i] = 1;
	int ki = 0;
	int i = 0;
	while (ki < n)
	{
		int ni = 0;
		while (ni < k)
		{
			if (i > n - 1)
				i = 0;
			if (peo[i] == 1)
				ni++;
			i++;
		}
		peo[i - 1 < 0 ? n - 1 : i - 1] = 0;
		kill[ki++] = i;
	}
	printf("<");
	for (int i = 0; i < n - 1; i++)
		printf("%d, ", kill[i]);
	printf("%d>", kill[n - 1]);
	return 0;
}
