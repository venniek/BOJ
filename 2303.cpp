#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int find_max(vector<int> num)
{
	int ret = 0;
	int sum;

	for (int i = 0; i < 3; i++)
	{
		for (int k = i + 1; k < 4; k++)
		{
			for (int j = k + 1; j < 5; j++)
			{
				sum = (num[i] + num[k] + num[j]) % 10;
				ret = max(ret, sum);
			}
		}
	}
	return (ret);
}

int main()
{
	int n;
	vector<int> num(5);
	vector<int> max;
	int ans = 0;

	cin >> n;
	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < 5; i++)
			cin >> num[i];
		max.push_back(find_max(num));
	}
	for (int i = 1; i < n; i++)
		if (max[i] >= max[ans]) ans = i;
	cout << ans + 1 << endl;
	return 0;
}
