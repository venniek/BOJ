#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, k;
	int tmp;
	vector<int> v;
	vector<int> lis;
	vector<int> idx;
	vector<int> ans;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		v.push_back(tmp);
		if (lis.empty() || lis.back() < tmp)
		{
			lis.push_back(tmp);
			idx.push_back(lis.size());
		}
		else
		{
			k = lower_bound(lis.begin(), lis.end(), tmp) - lis.begin();
			lis[k] = tmp;
			idx.push_back(k + 1);
		}
	}
	int size = lis.size();
	for (int i = n - 1; i >= 0 && size > 0; i--)
	{
		if (idx[i] == size)
		{
			ans.push_back(v[i]);
			size--;
		}
	}
	cout << lis.size() << endl;
	for (int i = 0; i < ans.size(); i++)
		cout << ans[ans.size() - i - 1] << " ";
	return 0;
}
