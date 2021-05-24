#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main()
{
	queue<int> q;
	int n;
	int push;
	string order;
	
	cin >> n;
	while (n-- > 0)
	{
		order.clear();
		cin >> order;
		if (order.compare("push") == 0)
		{
			cin >> push;
			q.push(push);
		}
		else if (order.compare("pop") == 0)
		{
			cout << (q.empty() ? -1 : q.front()) << endl;
			if (q.size() != 0) q.pop();
		}
		else if (order.compare("size") == 0)
			cout << q.size() << endl;
		else if (order.compare("empty") == 0)
			cout << (q.empty() ? 1 : 0) << endl;
		else if (order.compare("front") == 0)
			cout << (q.empty() ? -1 : q.front()) << endl;
		else if (order.compare("back") == 0)
			cout << (q.empty() ? -1 : q.back()) << endl;
	}
	return 0;
}

	
