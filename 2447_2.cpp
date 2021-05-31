#include <iostream>

int origin;

using namespace std;

void make_map(int **map, int n)
{
	if (n == 1)
		return ;
	for (int tmpi = 0; tmpi < origin / n; tmpi++) {
		for (int tmpk = 0; tmpk < origin / n; tmpk++) {
			for (int i = n / 3; i < n / 3 * 2; i++) {
				for (int k = n / 3; k < n / 3 * 2; k++)
					map[i + tmpi * n][k + tmpk * n] = 0;
			}
		}
	}
	make_map(map, n / 3);
}

int main()
{
	cin >> origin;
	int **map = new int *[origin];
	for (int i = 0; i < origin; i++)
	{
		map[i] = new int[origin];
		for (int k = 0; k < origin; k++)
			map[i][k] = 1;
	}
	make_map(map, origin);
	for (int i = 0; i < origin; i++) {
		for (int k = 0; k < origin; k++)
			cout << (map[i][k] == 1 ? '*' : ' ');
		cout << '\n';
	}
	return 0;
}
