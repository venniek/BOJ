#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long b_search(vector<long long> v, int len, int n)
{
	long long start = 1;
	long long end = v[len - 1];
	long long mid;
	long long sum;
	long long ret = 0;

	while (end - start >= 0)
	{
		sum = 0;
		mid = (start + end) / 2;
		for (int i = 0; i < len; i++)
			sum += v[i] / mid;
		if (sum < n)
			end = mid - 1;
		else
		{
			if (ret < mid)
				ret = mid;
			start = mid + 1;
		}
	}
	return (ret);
}

int main()
{
	int k, n;
	int tmp;

	cin >> k >> n;
	vector<long long> v;
	for (int i = 0; i < k; i++)
	{
		cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	cout << b_search(v, k, n);
	return 0;
}
