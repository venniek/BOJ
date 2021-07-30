#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n, x;
	priority_queue<int> q;

	cin >> n;
	while (n--)
	{
		cin >> x;
		if (x == 0 && q.empty())
			cout << 0 << '\n';
		else if (x == 0)
		{
			cout << q.top() << '\n';
			q.pop();
		}
		else
			q.push(x);
	}
	return 0;
}

