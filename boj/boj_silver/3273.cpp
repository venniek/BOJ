#include <iostream>
#include <algorithm>
using namespace std;

int n, x;
int arr[100002];
int ans;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
	cin >> x;
	int end = n - 1;
	for (int start = 0; start < end; start++)
	{
		while (end > start && arr[start] + arr[end] > x)
			end--;
		if (end == start)
			break;
		if (arr[start] + arr[end] == x)
		{
			ans++;
			end--;
		}
	}
	cout << ans;
	return 0;
}
