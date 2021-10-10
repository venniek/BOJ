#include <iostream>

using namespace std;

int n, m;
int done[9];

void find_nm(int cnt)
{
	if (cnt == m)
	{
		for (int i = 0; i < m; i++)
			cout << done[i] << " ";
		cout << '\n';
		return ;
	}
	for (int i = 1; i <= n; i++)
	{
		if (cnt != 0 && done[cnt - 1] > i)
			continue;
		done[cnt] = i;
		find_nm(cnt + 1);
		done[cnt] = 0;
	}
}

int main()
{
	cin >> n >> m;
	find_nm(0);
	return 0;
}