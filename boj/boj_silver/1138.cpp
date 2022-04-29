#include <iostream>

using namespace std;

int cnt[11];
int ans[11];
int done[11];
int n;

int is_right(int now, int i)
{
	int tmp = 0;

	for (int k = 1; k < now; k++)
	{
		if (ans[k] > ans[now])
			tmp++;
	}
	if (tmp == cnt[i])
		return 1;
	return 0;
}

void make_ans(int now)
{
	if (now == n + 1)
		return ;
	for (int i = 1; i <= n; i++)
	{
		ans[now] = i;
		if (done[i] == 1 || is_right(now, i) == 0)
			continue;
		done[i] = 1;
		make_ans(now + 1);
		if (ans[n] != 0)
			return ;
	}
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> cnt[i];
	make_ans(1);
	for (int i = 1; i <= n; i++)
		cout << ans[i] << " ";
	return 0;
}