#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, k;

	scanf("%d %d", &n, &k);
	vector< vector <int> > v(n + 1, vector<int>(n + 1, 0));
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (j == 0 || j == i)
				v[i][j] = 1;
			else
				v[i][j] = v[i - 1][j] + v[i - 1][j - 1];
			if (v[i][j] >= 10007)
				v[i][j] %= 10007;
	
		}
	}
	printf("%d", v[n][k]);
	return 0;
}
