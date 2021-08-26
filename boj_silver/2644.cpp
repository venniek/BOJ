#include <iostream>
#include <stack>

using namespace std;

int map[101];

int main()
{
	int n, a, b, m;
	stack<int> sa;
	stack<int> sb;

	cin >> n >> a >> b >> m;
    sa.push(a); sb.push(b);
	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		map[y] = x;
	}
	int tmp = a;
	while (map[tmp] != 0)
	{
		sa.push(map[tmp]);
		tmp = map[tmp];
	}
	tmp = b;
	while (map[tmp] != 0)
	{
		sb.push(map[tmp]);
		tmp = map[tmp];
	}
	if (sa.top() != sb.top())
		cout << -1;
	else
	{
		while (!sa.empty() && !sb.empty() && sa.top() == sb.top())
		{
			sa.pop();
			sb.pop();
		}
		cout << sa.size() + sb.size();
	}
	return 0;
}

