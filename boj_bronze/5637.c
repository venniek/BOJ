#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *make_str(char str[101])
{
	char *ans;

	ans = (char *)malloc(sizeof(char) * 101);
	int i = 0;
	int k = 0;
	while (str[i])
	{
		if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') 
				|| str[i] == '-') 
			ans[k++] = str[i];
		i++;
	}
	ans[k] = '\0';
	return (ans);
}

int main()
{
	char str[101];
	int max = 0;
	char ans[101];

	while (1)
	{
		scanf("%s", str);
		if (strcmp(str, "E-N-D") == 0)
			break;
		strcpy(str, make_str(str));
		if (max < (int)strlen(str))
		{
			max = (int)strlen(str);
			strcpy(ans, str);
		}
	}
	for (int i = 0; i < max; i++)
	{
		if (ans[i] >= 'A' && ans[i] <= 'Z')
			ans[i] += 'a' - 'A';
	}
	printf("%s", ans);
	return 0;
}		
