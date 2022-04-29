#include <iostream>
#include <queue>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

int n, m;
int map[55][55];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int isused[55];
vector<pair<int, int> > virus;
vector<pair<int, int> > selected;
int ans = 2147483647;

void BFS()
{
    int maxtmp = 1;
    int dis[55][55] = {0, };
    queue<pair<int, int> > q;
    for (int i = 0; i < selected.size(); i++)
    {
        q.push(selected[i]);
        dis[selected[i].first][selected[i].second] = 1;
    }
    while (!q.empty())
    {
        pair<int, int> cur;
        cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nowx = cur.first + dx[i];
            int nowy = cur.second + dy[i];

            if (nowx < 0 || nowx >= n || nowy < 0 || nowy >= n)
                continue;
            if (map[nowx][nowy] == 1 || dis[nowx][nowy] >= 1)
                continue;
            q.push({nowx, nowy});
            dis[nowx][nowy] = dis[cur.first][cur.second] + 1;
            if (map[nowx][nowy] != 2)
                maxtmp = max(dis[nowx][nowy], maxtmp);
        }
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
			if (map[i][j] == 0 && dis[i][j] == 0)
                return;
		}
    ans = min(ans, maxtmp - 1);
}

void DFS(int cnt)
{
    if (selected.size() == m)
    {
        BFS();
        return;
    }
    if (cnt == virus.size())
		return ;
	selected.push_back(virus[cnt]);
	DFS(cnt + 1);
	selected.pop_back();
	DFS(cnt + 1);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 2)
                virus.push_back(make_pair(i, j));
        }
    DFS(0);
    if (ans == 2147483647)
        cout << -1 << '\n';
    else
        cout << ans << '\n';
}