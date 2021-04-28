#include <stdio.h>
#include <math.h>

int find_pow(int n)
{
	int i = 0;
	while (n > pow(2, i + 1) || n <= pow(2, i))
		i++;
	return (pow(2, i));
}

int main()
{
	int n;
	int pown;

	scanf("%d", &n);
	if (n == 1)
	{
		printf("1");
		return 0;
	}
	pown = find_pow(n);
	printf("%d", (n - pown) * 2);
	return 0;
}
