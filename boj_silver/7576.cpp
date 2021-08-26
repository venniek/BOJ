#include <iostream>
#include <queue>

using namespace std;

int m, n;
int v[1002][1002];
queue<pair<int, int> > q;
pair<int, int> pop;

void is_que(int x, int y)
{
    int f = pop.first;
    int s = pop.second;

	if (v[f + x][s + y] == 0)
	{
		q.push(make_pair(f + x, s + y));
        v[f + x][s + y] = v[f][s] + 1;
	}
}

int tomato()
{
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
    int ans = v[1][1];
    for (int i = 1; i <= n; i++) {
        for (int k = 1; k <= m; k++) {
            if (v[i][k] == 0)
                return (-1);
            ans = max(ans, v[i][k]);
        }
    }
    return (ans - 1);
}

int main()
{
    cin >> m >> n;
    for (int i = 0; i < n + 2; i++)
        for (int k = 0; k < m + 2; k++) v[i][k] = -1;
    for (int i = 1; i <= n; i++) {
        for (int k = 1; k <= m; k++) {
            cin >> v[i][k];
            if (v[i][k] == 1)
                q.push(make_pair(i, k));
        }
    }
    cout << tomato();
    return 0;
}
