#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> nums;
int n, m, tmp, st, en;
int ans = 0;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		nums.push_back(tmp);
	}
	sort(nums.begin(), nums.end());
	st = 0; en = n - 1;
	while (st < en)
	{
		tmp = nums[st] + nums[en];
		if (tmp == m)
		{
			ans++;
			st++;
			en--;
		}
		else
			tmp < m ? st++ : en--;
	}
	cout << ans;
}