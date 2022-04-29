#include <iostream>

using namespace std;

int n, m;
int map[50][50];
string str;
int ans = 0;

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		for (int k = 0; k < m; k++)
			map[i][k] = str[k] - '0';	
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			for (int k = 1; k < min(n - i, m - j); k++)
			{
				if (map[i][j] == map[i + k][j] && map[i][j] == map[i][j + k])
				{
					if (map[i][j] == map[i + k][j + k])
						ans = max(ans, k);	
				}
			}
		}
	}
	cout << (ans + 1) * (ans + 1);
	return 0;
}