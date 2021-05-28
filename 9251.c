#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int len1, len2;
char s1[1001];
char s2[1001];

int max(int a, int b)
{
	return (a > b ? a : b);
}

int lcs(int **map, int k, int i)
{
	if (k == 0 || i == 0)
		return (0);
	else
	{
		if (s1[k - 1] == s2[i - 1])
			return (map[i - 1][k - 1] + 1);
		else
			return (max(map[i - 1][k], map[i][k - 1]));
	}
}

int main()
{
	int **map;

	scanf("%s %s", s1, s2);
	len1 = strlen(s1);
	len2 = strlen(s2);
	map = (int **)malloc(sizeof(int *) * (len2 + 1));
	for (int i = 0; i < len2 + 1; i++)
		map[i] = (int *)malloc(sizeof(int) * (len1 + 1));
	for (int i = 0; i < len2 + 1; i++)
	{
		for (int k = 0; k < len1 + 1; k++)
			map[i][k] = lcs(map, k, i);
	}
	printf("%d", map[len2][len1]);
	return 0;
}
