#include <stdio.h>
#include <string.h>

int main()
{
	char s[101];
	int ans[26] = { 0 };
	
	scanf("%s", s);
	for (int i = 0; i < 26; i++)
	{
		for (int k = 0; k < strlen(s); k++)
		{
			if (s[k] == 'a' + i)
				ans[i]++;
		}
	}
	for (int i = 0; i < 26; i++)
		printf("%d ", ans[i]);
	return 0;
}
