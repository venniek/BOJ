#include <iostream>

using namespace std;


int main()
{
	int n1, m1;
	int n2, m2;
	int a[100][100];
	int b[100][100];
	int sum;

	cin >> n1 >> m1;
	for (int i = 0; i < n1; i++)
	{
		for (int k = 0; k < m1; k++)
			cin >> a[i][k];
	}
	cin >> n2 >> m2;
	for (int i = 0; i < n2; i++)
	{
		for (int k = 0; k < m2; k++)
			cin >> b[i][k];
	}
	for (int i = 0; i < n1; i++)
	{
		for (int k = 0; k < m2; k++)
		{
			sum = 0;
				for (int l = 0; l < n2; l++)
					sum += a[i][l] * b[l][k];
			cout << sum << " ";
		}
		cout << endl;
	}
	return 0;
}
