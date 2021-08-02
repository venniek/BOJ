#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int len[4];
vector<pair<int, int> > v;

int main()
{
	int k;
	int dir;
	int length;
	int	big = 1;
	int empty = 1;

	cin >> k;
	for (int i = 0; i < 6; i++)
	{
		cin >> dir >> length;
		v.push_back(make_pair(dir, length));
		len[dir - 1]++;
	}
	if (v[5].first == v[1].first)
		empty *= v[0].second;
	for (int i = 1; i < 5; i++)
	{
		if (v[i - 1].first == v[i + 1].first)
			empty *= v[i].second;
	}
	if (v[4].first == v[0].first)
		empty *= v[5].second;
	for (int i = 0; i < 6; i++)
	{
		if (len[v[i].first - 1] == 1)
			big *= v[i].second;
	}
	cout << k * (big - empty);
	return 0;
}
