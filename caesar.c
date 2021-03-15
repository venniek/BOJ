#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *plus(const char *s, int i)
{
	int k = 0;
	char *str;

	if (!(str = (char *)malloc(sizeof(char) * (strlen(s) + 1))))
		return (NULL);
	while (s[k])
	{
		if (s[k] >= 'a' && s[k] <= 'z')
		{
			str[k] = s[k] + i;
			if (str[k] > 'z')
				str[k] = str[k] - 26;
			if (str[k] < 'a')
				str[k] = str[k] + 26;
		}
		else
			str[k] = ' ';
		k++;
	}
	str[k] = '\0';
	return (str);
}


int main()
{
	const char *s = "vla soxv ilyh";
	
	for (int i = -5; i < 6; i++)
		printf("%s\n", plus(s, i));
	
	return 0;
}

