#include <iostream>
using namespace std;

int main()
{
	int n;
	int num;
    long long d[21] = { 0, };
    
	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		long long tmp[21] = { 0, };
		cin >> num;
		if (i == 0)
			d[num] = 1;
		else
		{
			for (int j = 0; j < 21; j++)
			{
				if (d[j] != 0)
				{
					if (j + num <= 20)
						tmp[j + num] += d[j];
					if (j - num >= 0)
						tmp[j - num] += d[j];
				}
			}
			for (int j = 0; j < 21; j++)
				d[j] = tmp[j];
		}
	}
	cin >> num;
	cout << d[num];
	return 0;
}