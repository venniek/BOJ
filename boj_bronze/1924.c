#include <stdio.h>

int main()
{
	int x, y;
	int day = 0;
	char *yoil[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
	int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	scanf("%d %d", &x, &y);
	for (int i = 0; i < x - 1; i++)
		day += days[i];
	day += y;
	printf("%s", yoil[(day - 1) % 7]);
	return 0;
}
