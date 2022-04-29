#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
	int n1 = *(int *)a;
	int n2 = *(int *)b;

	if (n1 > n2)
		return 1;
	if (n1 < n2)
		return -1;
	return 0;
}

int search(int *arr, int len, int target)
{
	int start = 0;
	int end = len - 1;
	int mid;

	while (start <= end)
    {
		mid = (start + end) / 2;
		if (arr[mid] == target)
			return (mid);
		else
        {
			if (arr[mid] < target)
				start = mid + 1;
			else if (arr[mid] > target)
				end = mid - 1;
		}
	}
	return (-1);
}

int main()
{
	int *nnum;
	int mnum;
	int n, m;

	scanf("%d", &n);
	nnum = (int *)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
		scanf("%d", &nnum[i]);
	qsort(nnum, n, sizeof(int), cmp);
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &mnum);
		printf("%d\n", search(nnum, n, mnum) >= 0 ? 1 : 0);
	}
	return 0;
}
