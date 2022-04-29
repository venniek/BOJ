#include <stdio.h>
#include <string.h>

int main()
{
	int left, right, ans, t;
	char s[51];

	scanf("%d", &t);
	while (t-- > 0)	{
		left = 0;
		right = 0;
		ans = 0;
		scanf("%s", s);
		for (int i = 0; i < (int)strlen(s); i++) {
			if (s[i] == '(')
				left++;
			else if (s[i] == ')' && right < left)
				right++;
			else {
				ans = -1;
				break;
			}
		}
		if (left != right || ans == -1)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}
