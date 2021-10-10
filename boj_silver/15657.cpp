#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int ans[9];
int num[9];

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
		if (cnt != 0 && num[i] < ans[cnt - 1])
			continue;
		ans[cnt] = num[i];
		find_nm(cnt + 1);
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