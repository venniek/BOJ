#include <iostream>
using namespace std;

int n;
int price[1000][3];
int map[3][1000];

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 3; j++)
			cin >> price[i][j];
	for (int i = 0; i < 3; i++)
		map[i][0] = price[0][i];
	for (int i = 1; i < n; i++)
		for (int j = 0; j < 3; j++)
			map[j][i] = min(map[(j + 1) % 3][i - 1], map[(j + 2) % 3][i - 1]) + price[i][j];
	cout << min(min(map[0][n - 1], map[1][n - 1]), map[2][n - 1]);
	return 0;
}