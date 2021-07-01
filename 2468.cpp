#include <iostream>
#include <queue>

using namespace std;

int map[102][102];
int done[102][102];
int n;
int safe;
int safemax;
queue<pair<int, int> > q;
pair<int, int> pop;

void is_que(int x, int y)
{
    int f = pop.first + x;
    int s = pop.second + y;

	if (done[f][s] == 0 && f != 0 && f != n + 1 && s != 0 && s != n + 1)
	{
		q.push(make_pair(f, s));
        done[f][s] = 1;
	}
}

void bfs(int h)
{
	while (1)
	{
		if (q.empty() == 1)
		{
			safe++;
			return ;
		}
		pop = q.front();
		q.pop();
		is_que(1, 0);
		is_que(-1, 0);
		is_que(0, 1);
		is_que(0, -1);
	}
}

int bi(int h)
{
	for (int i = 1; i <= n; i++)
	{
		for (int k = 1; k <= n; k++)
		{
			if (map[i][k] <= h)
				done[i][k] = 1;
			else
				done[i][k] = 0;
		}
	}
	safe = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int k = 1; k <= n; k++)
		{
			if (done[i][k] == 0)
			{
				done[i][k] = 1;
				q.push(make_pair(i, k));
				bfs(h);
			}
		}
	}
	return (safe);
}
				



int main()
{
	int maxn = 0;

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int k = 1; k <= n; k++)
		{
			cin >> map[i][k];
			maxn = max(maxn, map[i][k]);
		}
	}
	for (int i = 0; i <= maxn; i++)
		safemax = max(safemax, bi(i));
	cout << safemax;
	return 0;
}
