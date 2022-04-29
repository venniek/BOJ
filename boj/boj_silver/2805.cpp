#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n, m;
	long long start;
	long long end;
	long long mid;
	long long sum;
	long long ret = 0;

	cin >> n >> m;
	vector<int> v(n);

	for (int i = 0; i < n; i++)
		scanf("%d", &v[i]);
	sort(v.begin(), v.end());
	start = 0;
	end = v[n - 1];
	while (end - start >= 0)
	{
		sum = 0;
		mid = (start + end) / 2;
		for (int i = 0; i < n; i++)
			sum += max((long long)0, v[i] - mid);
		if (sum >= m)
		{
			start = mid + 1;
			ret = max(ret, mid);
		}
		else if (sum < m)
			end = mid - 1;
	}
	cout << ret;
	return 0;
}

