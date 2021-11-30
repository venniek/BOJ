#include <iostream>

using namespace std;
int n;
int map[11][11];
int move1[21];
int move2[21];
int ans[2];

void DFS(int row, int col, int cnt, int color)
{
	if (col >= n)
	{
		row++;
		col = (col + 1) % 2;
	}
	if (row >= n)
	{
		ans[color] = max(ans[color], cnt);
		return ;
	}
	if (map[row][col] && !move1[col - row + n - 1] && !move2[row + col])
	{
		move1[col - row + n - 1] = 1;
		move2[row + col] = 1;
		DFS(row, col + 2, cnt + 1, color);
		move1[col - row + n - 1] = 0;
		move2[row + col] = 0;
	}
	DFS(row, col + 2, cnt, color);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];
	DFS(0, 0, 0, 0);
	DFS(0, 1, 0, 1);
	cout << ans[0] + ans[1];
}
