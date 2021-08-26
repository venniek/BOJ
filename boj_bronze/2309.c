#include <stdio.h>

int main()
{
	int h[9] = { 0 };
	int sum = 0;
	int diff;

	for (int i = 0; i < 9; i++)
	{
		scanf("%d", &h[i]);
		sum += h[i];
	}
	diff = sum - 100;
	for (int i = 0; i < 8; i++) {
		for (int k = i + 1; k < 9; k++)	{
			if (h[i] + h[k] == diff) {
				h[i] = 0;
				h[k] = 0;
				break;
			}
		}
		if (h[i] == 0)
			break;
	}
	for (int i = 0; i < 8; i++) {
		for (int k = i + 1; k < 9; k++) {
			if (h[i] > h[k]) {
				int tmp = h[i];
				h[i] = h[k];
				h[k] = tmp;
			}
		}
	}
	for (int i = 2; i < 9; i++)
		printf("%d\n", h[i]);
	return 0;
}
