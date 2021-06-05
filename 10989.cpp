#include <iostream>
using namespace std;

int cnt[10001] = { 0 };

int main()
{
	int n;
	int tmp;

	scanf("%d", &n);
	int ans[n];
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &tmp);
		cnt[tmp]++;
	}
	for (int i = 1; i < 10001; i++)
	{
		tmp = 0;
		while (cnt[i]-- > 0)
		{
			printf("%d\n", i);
			tmp++;
		}
		if (tmp == n)
			break;
	}
	return 0;
}
