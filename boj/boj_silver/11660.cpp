#include <iostream>
using namespace std;

int map[1026][1026];
int n, m;
int x1, x2, y1, y2;
int tmp;

int main()
{
	ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			cin >> tmp;
			map[i][j] = tmp + map[i][j - 1] + map[i - 1][j] - map[i - 1][j - 1];
		}
	while (m--)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		cout << map[x2][y2] - map[x1 - 1][y2] - map[x2][y1 - 1] + map[x1 - 1][y1 - 1] << '\n';
	}
	return 0;
}