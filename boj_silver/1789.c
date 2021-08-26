#include <stdio.h>
#include <math.h>

int main()
{
	unsigned long long s;
	unsigned long long n;

	scanf("%llu", &s);
	n = (sqrt(8 * s + 1) - 3) / 2;
	while (!(n * (n + 1) / 2 <= s && (n + 1) * (n + 2) / 2 > s))
		n++;
	printf("%llu", n);
	return 0;
}
