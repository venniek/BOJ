#include <iostream>

using namespace std;

int main()
{
	int n, m;
	int one, two, three, four;
	int ans = 1;

	cin >> n >> m;
	one = n;
	two = n / 2;
	three = (n + 1) / 2;
	four = (n + 2) / 3;
	
	if (one <= m)
		ans++;
	if (two <= m)
		ans++;
	if (three <= m)
		ans++;
	if (four <= m)
		ans++;
	if ((one + four) <= m)
		ans++;
	if ((two + four) <= m)
		ans++;
	if ((three + four) <= m)
		ans++;
	if (n == 1)
		ans = m == 0 ? 1 : 2;
	if (n == 2)
	{
		if (m == 0)
			ans = 1;
		else if (m == 1)
			ans = 3;
		else
			ans = 4;
	}
	cout << ans;
	return 0;
}
