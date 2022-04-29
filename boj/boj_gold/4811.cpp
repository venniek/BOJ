#include <iostream>
using namespace std;

int n;
long long dp[31][31];

void pill(int n)
{
	for (int i = 1; i <= n; i++)
		dp[i][1] = i;
	for (int i = 2; i <= n; i++)
		for (int j = 2; j <= n; j++)
		{
			if (i < j) continue;
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
}

int main()
{
	while (1)
	{
		cin >> n;
		if (n == 0)
			break;
		pill(n);
		cout << dp[n][n];
	}
}