#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char is_same(char arr[50][51], int i, int n)
{
	for (int k = 0; k < n - 1; k++)
	{
		if (arr[k][i] != arr[k + 1][i])
			return ('?');
	}
	return (arr[0][i]);
}


int main()
{
	int n;
	char arr[50][51];

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%s", arr[i]);
	for (int i = 0; i < strlen(arr[0]); i++)
		printf("%c", is_same(arr, i, n));
	return 0;
}
