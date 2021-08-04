#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> lis;

int main()
{
	int tmp;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		if (lis.empty() || lis.back() < tmp)
			lis.push_back(tmp);
		else
		{
			int k = lower_bound(lis.begin(), lis.end(), tmp) - lis.begin();
			lis[k] = tmp;
		}
	}
	cout << lis.size();
	return 0;
}
