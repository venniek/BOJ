#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int num[9];
int done[9];
int ans[9];

void find_nm(int cnt)
{
	if (cnt == m)
	{
		for (int i = 0; i < m; i++)
			cout << num[ans[i]] << " ";
		cout << '\n';
		return;
	}
	ans[cnt] = -1;
	for (int i = 0; i < n; i++)
	{
		if (done[i] == 0)
		{
			if (ans[cnt] != -1 && num[i] == num[ans[cnt]])
				continue;
			done[i] = 1;
			ans[cnt] = i;
			find_nm(cnt + 1);
			done[i] = 0;
		}
	}
}

int main()
{
	for (int i = 0; i < 9; i++)
		ans[i] = -1;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> num[i];
	sort(num, num + n);
	find_nm(0);
	return 0;
}

//8 8 10000 9999  9999 10000 10000 10000 9999 9999