#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int num[11];
int op[4];
vector<int> result;

int operate(int i, int num, int sum)
{
	if (i == 0)
		return num + sum;
	if (i == 1)
		return sum - num;
	if (i == 2)
		return num * sum;
	if (i == 3)
		return sum / num;
	return 0;
}

void func(int now, int sum)
{
	if (now == n)
	{
		result.push_back(sum);
		return ;
	}
	for (int i = 0; i < 4; i++)
	{
		if (op[i] != 0)
		{
			op[i]--;
			func(now + 1, operate(i, num[now], sum));
			op[i]++;
		}
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> num[i];
	for (int i = 0; i < 4; i++)
		cin >> op[i];
	func(1, num[0]);
	cout << *max_element(result.begin(), result.end()) << endl;
	cout << *min_element(result.begin(), result.end());
	return 0;
}
