#include <iostream>
#include <string>
#include <deque>

using namespace std;

deque<int> d;

int main()
{
	int t;

	cin >> t;
	while (t-- > 0)
	{
		int n;
		int x;
		int error = 0;
		char c;
		int dir = -1;
		deque<int> d;
		string p;

		cin >> p >> n;
		int len = p.size();
		cin >> c;
		while (1)
		{
			if (n == 0)
				break;
			cin >> x;
			d.push_back(x);
			if (d.size() == n)
				break;
			cin >> c;
		}
		cin >> c;
		for (int i = 0; i < len; i++)
		{
			if (p[i] == 'R')
				dir *= -1;
			else if (d.empty())
			{
				cout << "error\n";
				error = 1;
				break;
			}
			else
			{
				if (dir == -1)
					d.pop_front();
				else
					d.pop_back();
			}
		}
		if (error == 1)
			continue;
		cout << '[';
		if (!d.empty())
		{
			if (dir == -1)
			{
				for (int i = 0; i < d.size() - 1; i++)
					cout << d[i] << ",";
				cout << d[d.size() - 1];
			}
			else
			{
				for (int i = d.size() - 1; i > 0; i--)
					cout << d[i] << ",";
				cout << d[0];
			}
		}
		cout << "]\n";
	}
	return 0;
}
