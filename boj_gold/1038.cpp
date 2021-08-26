#include <iostream>
#include <queue>

using namespace std;

int n;
int cnt;
queue<long long > q;
long long nums[1030];

void find_num()
{
	while (!q.empty())
	{
		int last = q.front() % 10;
	
		for (int i = 0; i < last; i++)
		{
			q.push(q.front() * 10 + i);
			nums[cnt++] = q.back();
			if (cnt == n + 1)
				return ;
		}
		q.pop();
	}
}

int main()
{
	int len = 2;

	cin >> n;
	if (n >= 1023)
	{
		cout << -1;
		return 0;
	}
	if (n <= 9)
	{
		cout << n; 
		return 0;
	}
	for (int i = 0; i <= 9; i++)
	{
		q.push(i);
		nums[cnt++] = i;
	}
	find_num();
	cout << nums[n];
	return 0;
}
