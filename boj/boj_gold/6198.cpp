#include <iostream>
#include <stack>

using namespace std;

int main()
{
	int n;
	int tmp;
	stack<int> s;
	long long ans = 0;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		if (s.empty())
		{
			s.push(tmp);
			continue;
		}
		while (!s.empty() && s.top() <= tmp)
			s.pop();
		s.push(tmp);
		ans += s.size() - 1;
	}
	cout << ans;
	return 0;
}
