#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, m;
	int *num;
	int *search;
	int *ans;

	ans = (int *)malloc(sizeof(int) * 20000001);
	for (int i = 0; i < 20000001; i++)
		ans[i] = 0;
	scanf("%d", &n);
	num = (int *)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
		scanf("%d", &num[i]);
	scanf("%d", &m);
	search = (int *)malloc(sizeof(int) * m);
	for (int i = 0; i < m; i++)
		scanf("%d", &search[i]);
	for (int i = 0; i < n; i++)
		ans[num[i] + 10000000]++;
	for (int i = 0; i < m; i++)
		printf("%d ", ans[search[i] + 10000000]);
	return 0;
}
