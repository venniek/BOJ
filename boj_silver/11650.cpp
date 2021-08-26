#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int cmp(const pair<int, int> &a, const pair<int, int> &b)
{
	if (a.first == b.first)
		return (a.second < b.second);
	return (a.first < b.first);
}

int main()
{
	int n;

	cin >> n;
	vector< pair<int, int> > xy(n);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &xy[i].first, &xy[i].second);
	sort(xy.begin(), xy.end(), cmp);
	for (int i = 0; i < n; i++)
		printf("%d %d\n", xy[i].first, xy[i].second);
	return 0;

}
