#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	long long min;
	long long sum;

	cin >> n;
	vector<long long> distance(n - 1);
	vector<long long> price(n);
	for (int i = 0; i < n - 1; i++)
		cin >> distance[i];
	for (int i = 0; i < n; i++)
		cin >> price[i];
	min = price[0];
	sum += price[0] * distance[0];
	for (int i = 1; i < n - 1; i++)
	{
		if (price[i] < min)
			min = price[i];
		sum += min * distance[i];
	}
	cout << sum;
	return 0;
}
