#include <iostream>

using namespace std;

int bus[100][100];

int main()
{
	int n, m;
	int a, b, c;

	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		if (bus[a - 1][b - 1] == 0 || bus[a - 1][b - 1] > c)
			bus[a - 1][b - 1] = c;
	}
	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (bus[i][k] != 0 && bus[k][j] != 0)
				{
					if (bus[i][j] == 0 && i != j)
						bus[i][j] = bus[i][k] + bus[k][j];
					else
						bus[i][j] = min(bus[i][j], bus[i][k] + bus[k][j]);
				}
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int k = 0; k < n; k++)
			cout << bus[i][k] << " ";
		cout << endl;
	}
	return 0;
}

