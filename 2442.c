#include <stdio.h>

void print_star(int i, int n, int nl)
{
    if (i <= 2 * n - nl - 1)
        printf(" ");
    else
        printf("*");
	if (i == 2 * n - 1)
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
	print_star(1, n, n);
	return 0;
}
