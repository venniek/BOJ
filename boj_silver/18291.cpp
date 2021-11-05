#include <iostream>
using namespace std;

int t, n;

long long ans(int n)
{
	if (n == 1)
		return 2;
	if (n % 2 == 0)
		return ans(n / 2) * ans(n / 2) % 1000000007;
	else
		return ans(n / 2) * ans(n / 2) * 2 % 1000000007;
}

int main()
{
    ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--)
	{
		cin >> n;
		if (n == 1 || n == 2)
			cout << 1 << '\n';
		else
			cout << (int)ans(n - 2) << '\n';
	}
}
