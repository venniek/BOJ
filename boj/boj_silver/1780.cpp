#include <iostream>

using namespace std;

int minusone;
int zero;
int one;
int map[2187][2187];


void tritree(int n, int y, int x)
{
	int curr = map[y][x];

	if (n == 1)
	{
		if (curr == -1)
			minusone++;
		else if (curr == 0)
			zero++;
		else
			one++;
		return ;
	}
	for (int i = y; i < y + n; i++)
	{
		for (int k = x; k < x + n; k++)
		{
			if (map[i][k] != curr)
			{
				tritree(n / 3, y, x);
				tritree(n / 3, y, x + n / 3);
				tritree(n / 3, y, x + n / 3 * 2);
				tritree(n / 3, y + n / 3, x);
				tritree(n / 3, y + n / 3, x + n / 3);
				tritree(n / 3, y + n / 3, x + n / 3 * 2);
				tritree(n / 3, y + n / 3 * 2, x);
				tritree(n / 3, y + n / 3 * 2, x + n / 3);
				tritree(n / 3, y + n / 3 * 2, x + n / 3 * 2);
				return ;
			}
			else if (i == y + n - 1 && k == x + n - 1)
			{
				if (curr == -1)
					minusone++;
				else if (curr == 0)
					zero++;
				else
					one++;
			}
		}
	}
}




int main()
{
	int n;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int k = 0; k < n; k++)
			cin >> map[i][k];
	}
	tritree(n, 0, 0);
	printf("%d\n%d\n%d", minusone, zero, one);
}
