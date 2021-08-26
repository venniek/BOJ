#include <iostream>

using namespace std;

long long map[400][400];
int n;

void make_map()
{
	for (int i = 0; i < n; i++)
	{
		for (int k = 0; k < i + 1; k++)
		{
			if (i == k || k == 0)
				map[i][k] = 1;
			else
				map[i][k] = (map[i - 1][k - 1] % 1000000000 + map[i - 1][k] % 1000000000) % 1000000000;
		}
	}
}

int main()
{
	int k;

	cin >> n >> k;
	n += k;
	make_map();
	cout << map[n - 1][k - 1] % 1000000000;
	return 0;
}
