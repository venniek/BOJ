#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
	int sum = 0;
	char s[1000001];
	int len;
	int first;

	scanf("%s", s);
	len = strlen(s);
	if ((first = len % 3) != 0)
	{
		for (int i = 0; i < first; i++)
			sum += (s[i] - '0') * (first - i);
		printf("%d", sum);
	}
	for (int i = 0; i < len / 3; i++)
	{
		sum = 0;
		for (int k = 0; k < 3; k++)
			sum += (s[first + i * 3 + k] - '0') * pow(2, 2 - k);
		printf("%d", sum);
	}
	return 0;
}
