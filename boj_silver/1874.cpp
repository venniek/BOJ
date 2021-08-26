#include <iostream>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

stack<int> s;

int main()
{
	int n;
	int k = 1;
	int tmp;
	queue<int> q;
	vector<char> v;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		q.push(tmp);
	}
	while (q.empty() == 0)
	{
		if (k > n + 1)
		{
			cout << "NO";
			return (0);
		}
		if (s.empty() == 1 || q.front() != s.top())
		{
			v.push_back('+');
			s.push(k++);
		}
		else if (q.front() == s.top())
		{
			v.push_back('-');
			s.pop();
			q.pop();
		}
		else
		{
			cout << "NO";
			return (0);
		}
	}
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << "\n";
	return (0);
}
