#include <iostream>

using namespace std;
int n;

int star(int i, int j, int now)
{
	if (now == 1)
		return 1;
	if (i >= now / 3 && i < now - now / 3 && j >= now / 3 && j < now - now / 3)
		return 0;
	else
		return star(i % (now / 3), j % (now / 3), now / 3);
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (star(i, j, n) == 1)
				cout << "*";
			else
				cout << " ";
		}
		cout << '\n';
	}
	return 0;
}