#include <iostream>

using namespace std;

int d[2][100000];
int num[100000];

int main()
{
	int n;
	int des = 1, asc = 1;
	cin >> n;
	cin >> num[0];
	d[0][0] = 1;
	d[1][0] = 1;
	for (int i = 1; i < n; i++)
	{
		cin >> num[i];
		if (num[i] >= num[i - 1])
			d[0][i] = d[0][i - 1] + 1;
		else
			d[0][i] = 1;
		asc = max(asc, d[0][i]);
		if (num[i] <= num[i - 1])
			d[1][i] = d[1][i - 1] + 1;
		else
			d[1][i] = 1;
		des = max(des, d[1][i]);
	}
	cout << max(des, asc);
	return 0;
}