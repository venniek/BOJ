#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int cmp(const pair<int, int> &a, const pair<int, int> &b)
{
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int cmp(const pair<int, int> &a, const pair<int, int> &b)
{
	if (a.second == b.second)
		return (a.first < b.first);
	return (a.second < b.second);
}

int main()
{
	int n;
    
	cin >> n;
    vector< pair<int, int> > v(n);
	for (int i = 0; i < n; i++)
    {
        cin >> v[i].first;
        cin >> v[i].second;
    }
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < n; i++)
		cout << v[i].first << " " << v[i].second << "\n";
	return 0;
}

