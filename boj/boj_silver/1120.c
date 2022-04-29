#include <stdio.h>
#include <string.h>

int main()
{
	char a[51];
	char b[51];
	int alen;
	int blen;
	int minus;
	int min = 50;

	scanf("%s %s", a, b);
	alen = strlen(a);
	blen = strlen(b);
	for (int k = 0; k < blen - alen + 1; k++)
	{
		minus = 0;
		for (int i = 0; i < alen; i++)
			if (a[i] != b[k + i]) minus++;
		min = min > minus? minus : min;
	}
	printf("%d", min);
	return 0;
}
