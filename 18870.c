#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b)
{
	int n1 = *(int*)a;
	int n2 = *(int*)b;

    if (n1 == n2)
        return 0;
    return (n1 > n2 ? 1 : -1);
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
	int n;
	int* num;
	int* numcopy;
	int* numonly;

	scanf("%d", &n);
	num = (int*)malloc(sizeof(int) * n);
	numcopy = (int*)malloc(sizeof(int) * n);
	numonly = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &num[i]);
		numcopy[i] = num[i];
	}
	qsort(num, n, sizeof(int), compare);
	int j = 0;
	numonly[j++] = num[0];
	for (int i = 1; i < n; i++)
	{
		if (num[i] != num[i - 1])
			numonly[j++] = num[i];
	}
	for (int i = 0; i < n; i++)
		printf("%d ", search(numonly, j, numcopy[i]));
	return 0;
}
