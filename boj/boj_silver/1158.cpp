#include <iostream>
#include <queue>
#include <vector>

using namespace std;

queue<int> q;

int who_kill(int k)
{
	int ret;

	if (q.size() == 1)
		return (q.front());
	for (int i = 0; i < k - 1; i++)
	{
		q.push(q.front());
		q.pop();
	}
	ret = q.front();
	q.pop();
	return (ret);
}

int main()
{
	int n, k;
	vector<int> ans;

	cin >> n;
	cin >> k;
	for (int i = 0; i < n; i++)
		q.push(i + 1);
	for (int i = 0; i < n; i++)
		ans.push_back(who_kill(k));
	cout << '<';
	for (int i = 0; i < n - 1; i++)
		cout << ans.at(i) << ", ";
	cout << ans.back() << '>';
	return 0;
}
