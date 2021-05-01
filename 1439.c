#include <stdio.h>
#include <string.h>

int main()
{	
	char s[1000001];
	int n = 1;

	scanf("%s", s);
	int len = strlen(s);
	s[len] = '\0';
	for (int i = 0; i < len - 1; i++)
		if (s[i] != s[i + 1]) n++;
	printf("%d", n / 2);
	return 0;
}
