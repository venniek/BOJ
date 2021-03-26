#include <stdio.h>

int main()
{
	char a[5][16] = { 0 };

	for (int i = 0; i < 5; i++)
		scanf("%s", a[i]);
	for (int i = 0; i < 15; i++)
	{
		for (int k = 0; k < 5; k++)
		{
			if (a[k][i] == 0)
				continue;
			else
				printf("%c", a[k][i]);
		}
	}
	return 0;
}
