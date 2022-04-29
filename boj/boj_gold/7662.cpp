#include <iostream>
#include <queue>
#include <utility>

using namespace std;

struct cmp{
	bool operator()(pair<int, int> &a, pair<int, int> &b){
		return (a.first > b.first);
	}
};

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
	int t, k;
	char c;
	int n;

	cin >> t;
	while (t--)
	{
		priority_queue<pair<int, int> > bigq;
		priority_queue<pair<int, int>, vector<pair<int, int> >, cmp > smallq;
        int done[1000000] = { 0 };
		for (int i = 0; i < 1000000; i++)
			done[i] = 0;
		cin >> k;
		for (int i = 0; i < k; i++)
		{
			cin >> c >> n;
			if (c == 'I')
			{
				bigq.push(make_pair(n, i));
				smallq.push(make_pair(n, i));
			}
			else if (c == 'D')
			{
				if (n == 1 && !(bigq.empty()))
				{
					done[bigq.top().second] = 1;
					bigq.pop();
   				}
				else if (n == -1 && !(smallq.empty()))
				{
					done[smallq.top().second] = 1;
					smallq.pop();
				}
			}
			while (!bigq.empty() && (done[bigq.top().second] == 1))
				bigq.pop();
			while (!smallq.empty() && (done[smallq.top().second] == 1))
				smallq.pop();
		}
		if (bigq.empty() || smallq.empty())
			cout << "EMPTY\n";
		else
			cout << bigq.top().first << " " << smallq.top().first << "\n";
	}
	return 0;
}
