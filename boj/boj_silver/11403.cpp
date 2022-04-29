#include <iostream>

using namespace std;

int map[100][100];
int ans[100][100];

int main()
{
	int n;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int k = 0; k < n; k++)
			cin >> map[i][k];
	}
	int i = -1;
	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (map[i][k] + map[k][j] == 2)
					map[i][j] = 1;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int k = 0; k < n; k++)
			cout << map[i][k] << " ";
		cout << endl;
	}
	return 0;
}

