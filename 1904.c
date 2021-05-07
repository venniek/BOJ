#include <stdio.h>

int main()
{
	int n;
    int ans;
    
	scanf("%d", &n);
	int a = 1; int b = 2;
	if (n == 1)
        ans = a;
    else
    {
        for (int i = 0; i < n - 2; i++)
		{
			int tmp = b;
			b = (a + b) % 15746;
			a = tmp;
		}
    	ans = b;
	}
	printf("%d", ans);
	return 0;
}

