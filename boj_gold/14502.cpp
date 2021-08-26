#include <iostream>
#include <queue>
#include <algorithm>


using namespace std;

int m, n;
int maxsafe;
int map[10][10];
queue<pair<int, int> > q;
pair<int, int> pop;

void is_que(int x, int y)
{
    int f = pop.first + x;
    int s = pop.second + y;

	if (map[f][s] == 0 && f != 0 && f != n + 1 && s != 0 && s != m + 1)
	{
		q.push(make_pair(f, s));
        map[f][s] = 3;
	}
}

int virus()
{
	int tmp = 0;
    while (1)
    {
        if (q.empty())
            break;
        pop = q.front();
        q.pop();
        is_que(1, 0);
        is_que(-1, 0);
        is_que(0, 1);
        is_que(0, -1);
    }
	for (int i = 1; i <= n; i++) {
        for (int k = 1; k <= m; k++) {
            if (map[i][k] == 0)
                tmp++;
			if (map[i][k] == 3)
				map[i][k] = 0;
		}
    }
    return (tmp);
}

void make_wall(int cnt)
{
	if (cnt == 4)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int k = 1; k <= m; k++)
			{
				if (map[i][k] == 2)
					q.push(make_pair(i, k));
			}
		}
		maxsafe = max(maxsafe, virus());
		return ;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int k = 1; k <= m; k++)
		{
			if (map[i][k] == 0)
			{
				map[i][k] = 1;
				make_wall(cnt + 1);
				map[i][k] = 0;
			}
		}
	}
}


int main()
{
	cin >> n >> m;
    for (int i = 1; i <= n; i++)
	{
        for (int k = 1; k <= m; k++)
		{
			cin >> map[i][k];
			if (map[i][k] == 2)
				q.push(make_pair(i, k));
		}
	}
	make_wall(1);
	cout << maxsafe;
    return 0;
}

