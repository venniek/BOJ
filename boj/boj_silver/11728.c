#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, m;
	int *narr;
	int *marr;
	int *ans;

	scanf("%d %d", &n, &m);
	narr = (int *)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
		scanf("%d", &narr[i]);
	marr = (int *)malloc(sizeof(int) * m);
	for (int i = 0; i < m; i++)
		scanf("%d", &marr[i]);
	ans = (int *)malloc(sizeof(int) * (n + m));
	int ni = 0;
	int mi = 0;
	int i = 0;
	while (i < n + m)
	{
		if (narr[ni] <= marr[mi])
			ans[i++] = narr[ni++];
		else
			ans[i++] = marr[mi++];
		if (ni == n)
		{
			for (int k = mi; k < m; k++)
				ans[i++] = marr[k];
			break;
		}
		if (mi == m)
		{
			for (int k = ni; k < n; k++)
				ans[i++] = narr[k];
			break;
		}
	}
	for (int i = 0; i < n + m; i++)
		printf("%d ", ans[i]);
	return 0;
}	
