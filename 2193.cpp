#include <iostream>

using namespace std;

long long d[2][90];

int main()
{
	int n;

	cin >> n;
	d[0][0] = 0;
	d[1][0] = 1;
	for (int i = 1; i < n; i++)
	{
		d[0][i] = d[1][i - 1] + d[0][i - 1];
		d[1][i] = d[0][i - 1];
	}
	cout << d[0][n - 1] + d[1][n - 1];
	return 0;
}
