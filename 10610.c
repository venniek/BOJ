#include <stdio.h>
#include <string.h>

void ans_thirty(char *n, int len)
{
	for (int k = 9; k >= 0; k--)
	{
		for (int i = 0; i < len; i++)
		{
			if (n[i] - '0' == k)
				printf("%d", k);
		}
	}
}

int main()
{
	char n[100001];
	int len;
	int zero = 0;
	int sum = 0;

	scanf("%s", n);
	len = strlen(n);
	for (int i = 0; i < len; i++)
	{
		if (zero == 0 && n[i] == '0')
			zero = 1;
		sum += n[i] - '0';
	}
	if (!(sum % 3 == 0 && zero == 1))
		printf("-1");
	else
		ans_thirty(n, len);
	return (0);
}
