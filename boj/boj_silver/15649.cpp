#include <iostream>
using namespace std;

int n, m;
int ans[9];
int done[9];

void find_nm(int cnt)
{
	if (cnt == m)
	{
		for (int i = 0; i < m ; i++)
			cout << ans[i] << " ";
		cout << '\n';
		return ;
	}
	for (int i = 1; i <= n; i++)
	{
		if (done[i] == 1)
			continue;
		ans[cnt] = i;
		done[i] = 1;
		find_nm(cnt + 1);
		done[i] = 0;
	}
}

int main()
{
	cin >> n >> m;
	find_nm(0);
	return 0;
}