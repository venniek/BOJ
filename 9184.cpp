#include <iostream>
#include <cmath>
using namespace std;

int map[101][101][101];

int main()
{
	int a, b, c;
	int tmp;

	for (int i = 0; i <= 100; i++)
	{
		for (int k = 0; k <= 100; k++)
		{
			for (int j = 0; j <= 100; j++)
			{
				if (i <= 50 || k <= 50 || j <= 50)
					map[i][k][j] = 1;
				else if (i > 70 || k > 70 || j > 70)
					map[i][k][j] = pow(2, 20);
				else if (i < k && k < j)
					map[i][k][j] = map[i][k][j - 1] + map[i][k - 1][j - 1] - map[i][k - 1][j];
				else
					map[i][k][j] = map[i - 1][k][j] + map[i - 1][k - 1][j] + map[i - 1][k][j - 1] - map[i - 1][k - 1][j - 1];
			}
		}
	}
	while (1)
	{
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1)
			break;
		printf("w(%d, %d, %d) = %d\n", a, b, c, map[a + 50][b + 50][c + 50]);
	}
	return 0;
}

