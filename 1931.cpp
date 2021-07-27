#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;
vector<pair<int ,int> > v;

bool cmp(pair<int, int> &a, pair<int ,int> &b)
{
	if (a.second == b.second)
		return (a.first < b.first);
    return a.second < b.second;
}

int main()
{
    int ans = 0;
	int n;
	int start, end;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> start >> end;
		v.push_back({start, end});
	}
	sort(v.begin(), v.end(), cmp);
	int i = 0;
	int e = v[i].second;
	ans++;
    while (++i < v.size())
    {
        if (v[i].first >= e)
        {
            ans++;
            e = v[i].second;
        }
    }
	cout << ans;
}

