#include <iostream>
using namespace std;

int dp[1000005][2];
int n;

int main()
{
	cin >> n;
	dp[1][1] = 0; dp[1][0] = 0;
	dp[2][1] = 1; dp[2][0] = 1;
	dp[3][1] = 3; dp[3][0] = 1;
	for (int i = 4; i <= n; i++)
	{
		int one = dp[i - 1][0];
		int two = i % 2 == 0 ? dp[i / 2][0] : i;
		int three = i % 3 == 0 ? dp[i / 3][0] : i;
		if (one <= two && one <= three)
		{
			dp[i][0] = one + 1;
			dp[i][1] = 1;
		}
		else if (two <= one && two <= three)
		{
			dp[i][0] = two + 1;
			dp[i][1] = 2;
		}
		else
		{
			dp[i][0] = three + 1;
			dp[i][1] = 3;
		}
	}
	cout << dp[n][0] << '\n';
	while (n > 1)
	{
		cout << n << " ";
		n = dp[n][1] > 1 ? n / dp[n][1] : n - 1;
		if (n == 1)
			break;
	}
	cout << n;
	return 0;
}