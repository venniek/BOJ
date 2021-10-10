#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int ans[9];
int num[9];
int done[9];

void find_nm(int now, int cnt)
{
	if (cnt == m)
	{
		for (int i = 0; i < m; i++)
			cout << ans[i] << " ";
		cout << '\n';
		return ;
	}
	for (int i = 0; i < n; i++)
	{
		ans[cnt] = num[i];
		find_nm(i, cnt + 1);
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> num[i];
	sort(num, num + n);
	find_nm(0, 0);
	return 0;
}