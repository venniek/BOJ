#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> d;

int main()
{
	int n;
	int tmp;

	cin >> n;
	cin >> tmp;
	d.push_back(tmp);
	for (int i = 1; i < n; i++)
	{
		cin >> tmp;
		d.push_back(max(tmp, d.back() + tmp));
	}
	cout << *max_element(d.begin(), d.end());
	return 0;
}
