#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	int a, b;
	vector<pair<int, int> > v;
	vector<int> lis;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++)
	{
		if (lis.empty() || lis.back() < v[i].second)
			lis.push_back(v[i].second);
		else
			lis[lower_bound(lis.begin(), lis.end(), v[i].second) - lis.begin()] = v[i].second;
	}
	cout << n - lis.size();
	return 0;
}
