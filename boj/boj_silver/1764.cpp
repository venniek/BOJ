#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> listen;
vector<string> ans;

int cmp(string a, string b)
{
	if (a < b)
		return (1);
	return (0);
}


int main()
{
	int n, m;
	string tmp;

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		listen.push_back(tmp);
	}
	sort(listen.begin(), listen.end(), cmp);
	for (int i = 0; i < m; i++)
	{
		cin >> tmp;
		if (binary_search(listen.begin(), listen.end(), tmp))
			ans.push_back(tmp);
	}
	sort(ans.begin(), ans.end(), cmp);
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << endl;
}
