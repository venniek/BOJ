#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, k;
	int tmp;
	int sum = 0;
	vector<int> v;

	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		v.push_back(tmp);
	}
	for (int i = n - 1; i >= 0; i--)
	{
		if (v[i] > k)
			continue;
		sum += k / v[i];
		k -= k / v[i] * v[i];
	}
	cout << sum;
	return 0;
}

