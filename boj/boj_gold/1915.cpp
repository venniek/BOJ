#include <iostream>
using namespace std;

int ans[1000][1000];
int map[1000][1000];

int main()
{
	int n, m;
	int mx = 0;

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		string tmp;
		cin >> tmp;
		for (int k = 0; k < m; k++)
			map[i][k] = tmp[k] - '0';
	}
	for (int i = 0; i < n; i++)
	{
		for (int k = 0; k < m; k++)
		{
			if (i == 0 || k == 0)
				ans[i][k] = map[i][k];
			else if (map[i][k] == 1)
			{
				int mn = min(ans[i][k - 1], ans[i - 1][k]);
				mn = min(mn, ans[i - 1][k - 1]);
				ans[i][k] = mn + 1;		
			}
			mx = max(mx, ans[i][k]);
		}
	}
	cout << mx * mx;
	return 0;
}
