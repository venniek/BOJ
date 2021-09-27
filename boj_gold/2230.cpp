#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[100002];
int n, m;
int ans = 2147483647;

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
	int end = 0;
	for (int start = 0; start < n; start++)
	{
		while (end < n && arr[end] - arr[start] < m)
			end++;
		if (end == n)
			break;
		ans = min(ans, arr[end] - arr[start]);
	}
	cout << ans;
	return 0;
}

