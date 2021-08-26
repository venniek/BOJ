#include <iostream>
#include <vector>

using namespace std;

int map[102][102];
pair<int, int> home;
pair<int, int> rock;
vector<pair<int, int> > cvs;

int main()
{
	int t, n;
	int x, y;

	cin >> t;
	while (t-- > 0)
	{
		cin >> n;
		for (int i = 0; i < n + 2; i++)
		{
			cin >> x >> y;
			cvs.push_back(make_pair(x, y));
		}
		for (int i = 0; i < n + 2; i++)
		{
			for (int k = 0; k < n + 2; k++)
			{
				map[i][k] = abs(cvs[i].first - cvs[k].first) + abs(cvs[i].second - cvs[k].second) > 1000 ? 0 : 1;
			}
		}
		for (int k = 0; k < n + 2; k++)
		{
			for (int i = 0; i < n + 2; i++)
			{
				for (int j = 0; j < n + 2; j++)
				{
					if (map[i][k] + map[k][j] == 2)
						map[i][j] = 1;
				}
			}
		}
		if (map[0][n + 1] == 1)
			cout << "happy\n";
		else
			cout << "sad\n";
		cvs.clear();		
	}
	return 0;

}


