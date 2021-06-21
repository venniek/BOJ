#include <iostream>
#include <string>

using namespace std;

int map[64][64];

void quadtree(int n, int y, int x)
{
	int curr = map[y][x];
	if (n == 1)
	{
		printf("%d", curr);
		return ;
	}
	for (int i = y; i < y + n; i++)
	{
		for (int k = x; k < x + n; k++)
		{
			if (map[i][k] != curr)
			{
				printf("(");
				quadtree(n / 2, y, x);
				quadtree(n / 2, y, x + n / 2);
				quadtree(n / 2, y + n / 2, x);
				quadtree(n / 2, y + n / 2, x + n / 2);
				printf(")");
				return ;
			}
			else if (i == y + n - 1 && k == x + n - 1)
			{
				printf("%d", curr);
			}
		}
	}
}



int main()
{
	int n;
	
	cin >> n;
	string num[n];
	for (int i = 0; i < n; i++)
		cin >> num[i];
	for (int i = 0; i < n; i++)
	{
		for (int k = 0; k < n; k++)
			map[i][k] = num[i][k] - '0';
	}
	quadtree(n, 0, 0);
	return 0;
}
