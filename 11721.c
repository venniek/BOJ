#include <stdio.h>

int main()
{
	char str[101];
	int i = 0;

	scanf("%s", str);
	while (str[i])
	{
		int ten = 10;
		while (ten-- > 0 && str[i])
			printf("%c", str[i++]);
		printf("\n");
	}
	return 0;
}
