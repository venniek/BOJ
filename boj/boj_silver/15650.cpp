#include <iostream>

using namespace std;

int n, m;
int done[9];

void find_nm(int now, int cnt)
{
	if (cnt == m)
	{
		for (int i = 1; i <= 8; i++)
			if (done[i] == 1) cout << i << " ";
		cout << '\n';
		return ;
	}
	for (int i = now + 1; i <= n; i++)
	{
		done[i] = 1;
		find_nm(i, cnt + 1);
		done[i] = 0;
	}
}

int main()
{
	cin >> n >> m;
	find_nm(0, 0);
	return 0;
}