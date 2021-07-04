#include <iostream>

using namespace std;

int main()
{
	int x;
	int ans = 0;

	cin >> x;
	for (int i = 0; i < 7; i++)
	{
		if ((x & (1 << i)) != 0)
			ans++;
	}
	cout << ans;
	return 0;
}
