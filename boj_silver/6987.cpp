#include <iostream>

using namespace std;

int map[6][6];
int result[6][3];
int tmp[6][3];
int isright;

int make_result()
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 3; j++)
			result[i][j] = 0;
	}
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (i == j) continue;
			result[i][map[i][j]]++;
		}
		for (int j = 0; j < 3; j++)
		{
			if (tmp[i][j] != result[i][j])
				return 1;
		}
	}
	return 0;
}

void make_map(int row, int col)
{
	if (row == 5)
	{
		if (make_result() == 1)
			return ;
		isright = 1;
		return;
	}
	for (int i = 0; i <= 2; i++)
	{
		map[row][col] = i;
		map[col][row] = 2 - i;
		if (col == 5)
			make_map(row + 1, row + 2);
		else
			make_map(row, col + 1);
		if (isright == 1)
			return;
	}
}

int check_first()
{
	int sumrow;
	int sumwin = 0;
	int sumlose = 0;
	int sumdraw = 0;

	for (int i = 0; i < 6; i++)
	{
		sumrow = 0;
		for (int j = 0; j < 3; j++)
			sumrow += tmp[i][j];
		if (sumrow != 5)
			return 1;
		sumwin += tmp[i][0];
		sumdraw += tmp[i][1];
		sumlose += tmp[i][2];
	}
	if (sumwin != sumlose)
		return 1;
	if (sumdraw % 2)
		return 1;
	return 0;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	for (int i = 0; i < 4; i++)
	{
		isright = 0;
		for (int j = 0; j < 6; j++)
			for (int k = 0; k < 3; k++)
				cin >> tmp[j][k];
		if (check_first())
		{
			cout << 0 << " ";
			continue;
		}
		make_map(0, 1);
		cout << isright << " ";
	}
}