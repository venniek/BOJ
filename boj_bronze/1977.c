#include <stdio.h>
#include <math.h>

int main()
{
	int m,n;
	int min;
	int sum = 0;

	scanf("%d %d", &m, &n);
	while (n >= m)
	{
		if (sqrt(n) == (int)sqrt(n))
		{
			min = n;
			sum+= n;
		}
		n--;
	}
	if (sum == 0)
		printf("-1");
	else
		printf("%d\n%d", sum, min);
	return 0;
}
