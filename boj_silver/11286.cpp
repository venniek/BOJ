#include <iostream>
#include <queue>

using namespace std;

priority_queue<pair<int, int> , vector<pair<int, int> >, greater<pair<int, int> > > q;

int main()
{
	int n;
	int tmp;

	cin >> n;
	while (n-- > 0)
	{
		cin >> tmp;
		if (tmp == 0)
		{
			if (q.empty() == 1)
				cout << 0 << endl;
			else
			{	
				cout << q.top().first * q.top().second << endl;
				q.pop();
			}
		}
		else
		{
			if (tmp > 0)
				q.push(make_pair(tmp, 1));
			else
				q.push(make_pair(tmp * -1, -1));
		}
	}
	return 0;
}
