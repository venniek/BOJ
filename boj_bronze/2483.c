#include <stdio.h>

void print_star(int i, int n, int nl)
{
	printf("*");
	if (i == n)
		return ;
	if (i == nl)
	{
        i = 0;
        nl++;
		printf("\n");
	}
    print_star(i + 1, n, nl);
}

int main()
{
	int n;

	scanf("%d", &n);
	print_star(1, n, 1);
	return 0;
}
