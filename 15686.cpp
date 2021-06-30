#include <iostream>
#include <utility>
#include <cmath>
#include <vector>

using namespace std;

int map[50][50];
int n, m;
vector<pair<int, int> > chi;
vector<pair<int, int> > home;
int ans = 2147483647;


int distance()
{
	int dismin;
	int sum = 0;

	for (int i = 0; i < home.size(); i++)
	{
		dismin = 2147483647;
		for (int k = 0; k < chi.size(); k++)
		{
			int tmp;
			tmp = abs(chi[k].first - home[i].first) + abs(chi[k].second - home[i].second);
			dismin = min(dismin, tmp);
		}
		sum += dismin;
	}
	return (sum);
}

void chicken(int index)
{
	if (index == m)
	{
		ans = min(ans, distance());
		return ;
	}
	for (int i = chi.empty() == 1 ? 0 : chi.back().second; i < n; i++)
	{
		for (int k = 0; k < n; k++)
		{
			if (chi.empty() == 0)
			{
				if (i == chi.back().second && k <= chi.back().first)
					continue;
			}
			if (map[i][k] == 2)
			{	
				chi.push_back(make_pair(k, i));
				chicken(index + 1);
				chi.pop_back();
			}
		}
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int k = 0; k < n; k++)
		{
			cin >> map[i][k];
			if (map[i][k] == 1)
				home.push_back(make_pair(k, i));
		}
	}
	chicken(0);
	cout << ans;
	return 0;
}

