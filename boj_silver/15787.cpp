#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, m;
	int order;
	int i, x;
	int ans = 0;

	cin >> n >> m;
	vector<int> train(n + 1, 0);
	for (int k = 0; k < m; k++)
	{
		cin >> order;
		if (order == 1 || order == 2)
		{	
			cin >> i >> x;
			if (order == 1)
				train[i] |= 1 << (20 - x);
			if (order == 2)
				train[i] &= ~(1 << (20 - x));
		}
		else
		{
			cin >> i;
			if (order == 3)
				train[i] >>= 1;
			if (order == 4)
			{
				train[i] <<= 1;
				train[i] &= ~(1 << 20);
			}
		}
	}
	vector<bool> done(1 << 21, false);
	for (int i = 1; i <= n; i++)
	{
		if (done[train[i]] == false)
		{
			done[train[i]] = true;
			ans++;
		}
	}
	cout << ans;
	return 0;
}
