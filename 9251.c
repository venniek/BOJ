#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(int a, int b)
{
	return (a > b ? a : b);
}

int main()
{
	int len1, len2;
	char s1[1001];
	char s2[1001];
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
		{
			int ans;
			if (k == 0 || i == 0)
				ans = 0;
			else
			{
				if (s1[k - 1] == s2[i - 1])
					ans = map[i - 1][k - 1] + 1;
				else
					ans = (max(map[i - 1][k], map[i][k - 1]));
			}
			map[i][k] = ans;
	}
	printf("%d", map[len2][len1]);
	return 0;
}
