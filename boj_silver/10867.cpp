#include <iostream>
using namespace std;

int n;
int nums[2002];

int main()
{
	int n;
	int tmp;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		nums[tmp + 1000]++;
	}
	for (int i = 0; i <= 2000; i++)
	{
		if (nums[i] > 0)
			cout << i - 1000 << " ";
	}
}