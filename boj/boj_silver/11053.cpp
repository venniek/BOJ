#include <iostream>

using namespace std;

int main()
{
	int n;
	int num[1000];
	int ans[1000];
    int ret = 0;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num[i];
		ans[i] = 1;
		for (int k = 0; k < i; k++)
		{
			if (num[i] > num[k])
				ans[i] = max(ans[i], ans[k] + 1);
		}
		ret = max(ans[i], ret);
	}
	cout << ret;
	return 0;
}

