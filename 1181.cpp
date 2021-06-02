#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int cmp(pair <string, int> &a, pair <string, int> &b)
{
	if (a.second == b.second)
		return (a.first < b.first);
	return (a.second < b.second);
}


int main()
{
	int n;

	scanf("%d", &n);
	vector <pair <string, int> > arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i].first;
		arr[i].second = arr[i].first.size();
	}
	sort(arr.begin(), arr.end(), cmp);
	cout << arr[0].first << '\n';
	for (int i = 1; i < n; i++)
	{
		if (arr[i].first != arr[i - 1].first)
			cout << arr[i].first << '\n';
	}
	return 0;
}
