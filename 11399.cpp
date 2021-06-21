#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	int tmp;
	int sum = 0;
	vector<int> v;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++)
		sum += v[i] * (n - i);
	cout << sum;
	return 0;
}
