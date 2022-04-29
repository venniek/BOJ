#include <stdio.h>

int main()
{
	int e, s, m;
	int year = 1;

	scanf("%d %d %d", &e, &s, &m);
	if (e == 15)
		e = 0;
	if (s == 28)
		s = 0;
	if (m == 19)
		m = 0;
	while (!(year % 15 == e && year % 28 == s && year % 19 == m))
		year++;
	printf("%d", year);
	return (0);
}
