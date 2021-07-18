#include <iostream>
#include <queue>
#include <utility>

using namespace std;


int find_max(queue<pair<int, int> > q)
{
	int maxn = 0;
	for (int i = 0; i < q.size(); i++)
	{
		maxn = max(maxn, q.front().first);
		q.push(q.front());
		q.pop();
	}
	return (maxn);
}

int main()
{
	int t, n, m;
	int tmp;

	cin >> t;
	while (t-- > 0)
	{
		queue<pair<int, int> > q;
		cin >> n >> m;
		for (int i = 0; i < n; i++)
		{
			cin >> tmp;
			q.push(make_pair(tmp, i));
		}
		int cnt = 1;
		while (1)
		{
			int maxn = find_max(q);
			while (q.front().first != maxn)
			{
				q.push(q.front());
				q.pop();
			}
			if (q.front().second == m)
				break;
			else
			{
				q.pop();
				cnt++;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}
