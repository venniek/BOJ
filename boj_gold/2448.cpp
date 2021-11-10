#include <iostream>
using namespace std;

int n;
int map[5000][7000];

void star(int lv, int row, int col)
{
	if (lv == 3)
	{
		map[row][col] = 1;
		map[row + 1][col - 1] = 1;
		map[row + 1][col + 1] = 1;
		for (int i = col - 2; i <= col + 2; i++)
			map[row + 2][i] = 1;
		return ;
	}
	star(lv / 2, row, col);
	star(lv / 2, row + lv / 2, col - lv / 2);
	star(lv / 2, row + lv / 2, col + lv / 2);
}

int main()
{
	cin >> n;
	star(n, 0, n - 1);
	star(n, n / 2, n - 1 - n / 2);
	star(n, n / 2, n - 1 + n / 2);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 2 * n - 1; j++)
			cout << (map[i][j] == 1 ? '*' : ' ');
		cout << '\n';
	}
	return 0;
}