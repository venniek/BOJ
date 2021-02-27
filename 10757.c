#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int numlen(int a)
{
	int i = 0;

	while (a > 0)
	{
		a /= 10;
		i++;
	}
	return (i);
}

int main()
{
	char a[10000];
	char b[10000];
	int alen;
	int blen;
	int anslen;
	int t;
	char *ans;
	int i = 0;
	int k = 0;

	scanf("%s %s", a, b);
	alen = strlen(a);
	blen = strlen(b);
	anslen = (alen >= blen ? alen : blen);
	t = anslen;
	ans = (char *)malloc(sizeof(char) * (t + 2));
	while (blen > 0 && alen > 0)
	{
		if ((k = i + a[--alen] - '0' + b[--blen] - '0') >= 10)
			i = 1;
		else
			i = 0;
		ans[t--] = k % 10 + '0';
	}
	while (t > 0)
	{
		if ((k = i + a[--alen] - '0') >= 10)
			i = 1;
		else
			i = 0;
		ans[t--] = k % 10 + '0';
	}
	ans[0] = i + '0';
	ans[anslen + 1] = '\0';
	free(ans);
	return 0;
}
