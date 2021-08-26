#include <stdio.h>
#include <math.h>

int main()
{
	int x;
	int y;
	int num = 0;
	long long dist;
	int t;
	int index;

	scanf("%d", &t);
	
	while (t-- > 0)
	{
		scanf("%d %d", &x, &y);
		dist = y - x;
		index = (int)sqrt(dist);
		if (dist == index * index)
			num = 2 * index - 1;
		else if (dist > index * index && dist <= index * index + index)
			num = 2 * index;
		else
			num = 2 * index + 1;
		
		printf("%d\n", num);
	}

	return 0;
}

