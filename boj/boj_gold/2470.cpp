#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int num[100001];
int n, sum, mina, minb;
int minans = 2147483647;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> num[i];
	sort(num, num + n);
	int start = 0; int end = n - 1;
	while (start < end)
	{
		sum = num[start] + num[end];
		if (minans > abs(sum))
		{
			minans = abs(sum);
			mina = num[start];
			minb = num[end];
		}
		if (sum == 0)
			break;
		sum > 0 ? end-- : start++;
	}
	cout << mina << " " << minb;
	return 0;
}