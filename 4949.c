#include <stdio.h>
#include <string.h>

int main()
{
	int ans;
	char str[101] = "\0";
	char brac[51] = "\0";

	while (1)
	{
		gets(str);
		if (strcmp(str, ".") == 0)
			break;
		int k = 0;
		ans = 1;
		for (int i = 0; i < strlen(str); i++)
		{
			if (str[i] == '(' || str[i] == '[')
				brac[k++] = str[i];
			else if (str[i] == ')')
			{
				if (k == 0 || brac[k - 1] != '(')
				{
					ans = -1;
					break;
				}
				else
					k--;
			}
			else if (str[i] == ']')
			{
				if (k == 0 || brac[k - 1] != '[')
				{
					ans = -1;
					break;
				}
				else
					k--;
			}
		}
		if (k != 0)
			ans = -1;
		printf("%s\n", ans == 1 ? "yes" : "no");
		str[0] = '\0';
		brac[0] = '\0';
	}
	return 0;
}

