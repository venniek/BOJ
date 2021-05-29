#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main()
{
	int n;
	vector<int> score(301, 0);
	vector<pair<int, int> > p;

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> score[i];
	p.push_back(make_pair(score[1], score[1]));
	p.push_back(make_pair(score[2], score[1] + score[2]));
	for (int i = 3; i <= n; i++)
		p.push_back(make_pair(max(p[i - 3].first, p[i - 3].second) + score[i], p[i - 2].first + score[i]));
	cout << max(p[n - 1].first, p[n - 1].second);
	return 0;
}
