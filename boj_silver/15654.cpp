#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int ans[9];
int num[9];
int done[9];

void find_nm(int cnt)
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
		if (done[i] != 0)
			continue;
		done[i] = 1;
		ans[cnt] = num[i];
		find_nm(cnt + 1);
		done[i] = 0;
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> num[i];
	sort(num, num + n);
	find_nm(0);
	return 0;
}