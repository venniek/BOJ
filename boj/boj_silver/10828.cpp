#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
	stack<int> s;
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
			s.push(push);
		}
		else if (order.compare("pop") == 0)
		{
			cout << (s.empty() ? -1 : s.top()) << '\n';
			if (s.size() != 0) s.pop();
		}
		else if (order.compare("size") == 0)
			cout << s.size() << '\n';
		else if (order.compare("empty") == 0)
			cout << (s.empty() ? 1 : 0) << '\n';
		else if (order.compare("top") == 0)
			cout << (s.empty() ? -1 : s.top()) << '\n';
	}
	return 0;
}

	
