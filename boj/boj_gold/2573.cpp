#include <iostream>
#include <queue>
#include <utility>
#include <cstring>
using namespace std;

int map[305][305];
int vis[305][305];
int melt[305][305];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int N, M, year;
queue<pair<int, int> > q;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> map[i][j];
    while (1)
    {
        year++;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
            {
                if (map[i][j] != 0)
                {
                    int tmp = 0;
                    for (int k = 0; k < 4; k++)
                    {
                        int nx = i + dx[k];
                        int ny = j + dy[k];
                        if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                            continue;
                        if (map[nx][ny] == 0)
                            tmp++;
                    }
                    melt[i][j] = tmp;
                }
            }
        int flag = 0;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
            {
                if (melt[i][j] > 0)
                {
                    flag = 1;
                    map[i][j] -= min(melt[i][j], map[i][j]);
                }
                melt[i][j] = 0;
            }
        if (flag == 0)
        {
            cout << 0;
            return 0;
        }
        memset(vis, 0, sizeof(vis));
        int dis = 1;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
            {
                if (map[i][j] != 0 && vis[i][j] == 0)
                {
					if (dis > 1)
               		{
            	        cout << year;
                	    return 0;
                	}
                    q.push({i, j});
                    vis[i][j] = dis;
                }
                while (!q.empty())
                {
                    pair<int, int> cur = q.front();
                    q.pop();
                    for (int dir = 0; dir < 4; dir++)
                    {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];
                        if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                            continue;
                        if (vis[nx][ny])
                            continue;
						if (map[nx][ny] > 0)
                        {
							q.push({nx, ny});
                        	vis[nx][ny] = dis;
						}
                    }
					if (q.empty())
						dis++;
                }
            }
    }
    return 0;
}
