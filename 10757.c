#include <stdio.h>
#include <string.h>

void str_swap(char *s)
{
	int len = strlen(s);
	
	for (int i = 0; i < len / 2; i++)
	{
		char tmp = s[i];
		s[i] = s[len - i - 1];
		s[len - i - 1] = tmp;
	}
}

int main()
{
	char a[10002] = {0};
	char b[10002] = {0};
	char ans[100003] = {0};
	int olim = 0;
	int large;
	int plus;
	int i;

	scanf("%s %s", a, b);
	str_swap(a);
	str_swap(b);
	large = strlen(a) > strlen(b) ? strlen(a) : strlen(b);
	for (i = 0; i < large; i++)
	{
		plus = a[i] - '0' + b[i] - '0' + olim;
		while (plus < 0)
			plus += '0';
		if (plus > 9)
			olim = 1;
		else
			olim = 0;
		ans[i] = plus % 10 + '0';
	}
	if (olim == 1)
		ans[i++] = '1';
	ans[i] = '\0';
	str_swap(ans);
	printf("%s", ans);
	return 0;
}
