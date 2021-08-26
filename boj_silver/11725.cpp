#include <iostream>
#include <vector>

using namespace std;

#define MAX 100001

int done[MAX];
int ans[MAX];
vector<int> v[MAX];

void find_parent(int index)
{
	for (int i = 0; i < v[index].size(); i++)
	{
		int next = v[index][i];
		if (done[next] == 0)
		{
			ans[next] = index;
			done[next] = 1;
			find_parent(next);
		}
	}
}


int main()
{
	int n;
	int a, b;

	cin >> n;
	for (int i = 1; i < n; i++)
	{
		cin >> a;
		cin >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	done[1] = 1;
	find_parent(1);
	for (int i = 2; i <= n; i++)
		cout << ans[i] << '\n';
	return 0;
}
