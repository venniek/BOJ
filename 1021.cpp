#include <iostream>
#include <deque>

using namespace std;

deque<int> d;

void rotate_d(int i)
{
	if (i == 1)
	{	
		d.push_back(d.front());
		d.pop_front();
	}
	else
	{
		d.push_front(d.back());
		d.pop_back();
	}
}


int main()
{
	int n, m;
	int sum = 0;
	int tmp;

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		d.push_back(i);
	for (int i = 0; i < m; i++)
	{
		cin >> tmp;
		if (tmp == d.front())
			d.pop_front();
		else
		{
			int k = 1;
			while (d.at(k) != tmp)
				k++;
			if (k < (d.size() + 1) / 2)
			{
				for (int j = 0; j < k; j++)
					rotate_d(1);
				sum += k;
			}
			else
			{
				for (int j = k; j < d.size(); j++)
					rotate_d(2);
				sum += d.size() - k;
			}
			d.pop_front();
		}
	}
	cout << sum;
	return 0;
}
