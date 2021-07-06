#include <iostream>
#include <vector>

using namespace std;

vector<int> v(11, 0);
int n, m;

int team()
{
	int minnum = 2147483647; 

	for (int i = 0; i < (1 << m); i++)
	{
		int ans = 0;
		int ret = 0;
		for (int j = 0; j < m; j++)
		{
			if (i & (1 << j))
			{
				ret |= v[j];
				ans++;
			}
		}
		if (ret == (1 << (n)) - 1)
			minnum = min(minnum, ans);
	}
	return (minnum);
}


int main()
{
	int a;
	int tmp;
	int ret;

	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> a;
		for (int k = 0; k < a; k++)
		{
			cin >> tmp;
			v[i] |= 1 << (tmp - 1);
		}
	}
	ret = team();
	if (ret == 2147483647)
		cout << "-1";
	else
		cout << ret;
	return 0;
}
