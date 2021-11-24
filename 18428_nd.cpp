#include <iostream>
using namespace std;

int yescan;
int n, stu;
char map[8][8];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void can_we()
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			if (map[i][j] == 'T')
			{
				for (int k = 0; k < 4; k++)
				{
					int nx = i + dx[k];
					int ny = j + dy[k];
					while (1)
					{
						if (map[nx][ny])
					}
				}
			}
		}
}

void add_wall(int x, int y, int now)
{
	if (now == 3)
	{
		can_we();
		return;
	}
	for (int i = x; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == x && j < y) continue;
			if (map[i][j] == 'X')
			{
				map[i][j] == 'O';
				add_wall(i, j + 1, now + 1);
				if (yescan == 1)
					return;
				map[i][j] == 'X';
			}
		}
	}

}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 's')
				stu++;
		}
	add_wall(1, 1, 0);
	cout << (yescan == 1) ? "YES" : "NO";
}