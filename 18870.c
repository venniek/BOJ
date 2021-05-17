#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b)
{
	int num1 = *(int*)a;
	int num2 = *(int*)b;

	if (num1 < num2)
		return -1;
	if (num1 > num2)
		return 1;
	return 0;
}

int search(int* arr, int length, int target)
{
	int start = 0;
	int end = length - 1;
	int mid = 0;
	while (start <= end) {
		mid = (start + end) / 2;
		if (arr[mid] == target)
			return mid;
		else {
			if (arr[mid] < target)
				start = mid + 1;
			else if (arr[mid] > target)
				end = mid - 1;
		}
	}
	return -1;
}

int main()
{
	int n;
	int* num;
	int* numc;
	int* nums;
	int* ans;

	scanf("%d", &n);
	num = (int*)malloc(sizeof(int) * n);
	numc = (int*)malloc(sizeof(int) * n);
	nums = (int*)malloc(sizeof(int) * n);
	ans = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &num[i]);
		numc[i] = num[i];
	}
	qsort(num, n, sizeof(int), compare);
	int j = 0;
	nums[j++] = num[0];
	for (int i = 1; i < n; i++)
	{
		if (num[i] != num[i - 1])
			nums[j++] = num[i];
	}
	for (int i = 0; i < n; i++)
		ans[i] = search(nums, j, numc[i]);
	for (int i = 0; i < n; i++)
		printf("%d ", ans[i]);

	return 0;
}
