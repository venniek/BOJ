#include <stdio.h>

int main()
{
	int n;
	char s[6];
	int ans;

	while (1)
	{
		ans = 0;
		s[0] = '\0';
		scanf("%d", &n);
		if (n == 0)
			break;
		int i = 0;
		while (n > 0)
		{
			s[i++] = n % 10;
			n /= 10;
		}
		s[i] = '\0';
		for (int k = 0; k < i / 2; k++)
			if (s[k] != s[i - k - 1]) ans = 1;
		printf("%s\n", ans == 1 ? "no" : "yes");
	}
	return 0;
}
