#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int r, c;
char map[250][250];
int done[250][250];
int sheep, wolf;
int tmps, tmpw;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
queue<pair<int, int> > q;

int main()
{
	cin >> r >> c;
	for (int i = 0; i < r; i++)
	{
		string tmp;
		cin >> tmp;
		for (int j = 0; j < c; j++)
			map[i][j] = tmp[j];
	}
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
		{
			if (map[i][j] != '#' && done[i][j] == 0)
			{
				q.push(make_pair(i, j));
				done[i][j] = 1;
				tmps = 0; tmpw = 0;
				while (!q.empty())
				{
					pair<int, int> cur = q.front();
					q.pop();
					tmps += map[cur.first][cur.second] == 'o' ? 1 : 0;
					tmpw += map[cur.first][cur.second] == 'v' ? 1 : 0;
					for (int k = 0; k < 4; k++)
					{
						int nowy = cur.first + dy[k];
						int nowx = cur.second + dx[k];
						if (nowy < 0 || nowy >= r ||
							nowx < 0 || nowx >= c)
							continue;
						if (map[nowy][nowx] != '#' && done[nowy][nowx] == 0)
						{
							q.push(make_pair(nowy, nowx));
							done[nowy][nowx] = 1;
						}
					}
				}
				if (tmps > tmpw)
					sheep += tmps;
				else
					wolf += tmpw;
			}
		}
	cout << sheep << " " << wolf;
	return 0;
}
