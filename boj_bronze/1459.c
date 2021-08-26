#include <stdio.h>

int main()
{
	long long x, y, w, s;
	long long min, max;
	long long ans;

	scanf("%lld %lld %lld %lld", &x, &y, &w, &s);

	if (2 * w <= s)
		ans = (x + y) * w;
	else if (x == y)
		ans = s * x;
	else
	{
		min = x > y ? y : x;
		max = x > y ? x : y;
		ans = min * s;
		if (w <= s)
			ans += (max - min) * w;
		else
		{
			if ((max - min) % 2 == 0)
				ans += (max - min) * s;
			else
				ans += (max - min - 1) * s + w;
		}
	}
	printf("%lld", ans);
	return 0;
}
