#include <iostream>
#include <queue>
#include <string>

using namespace std;
string map[1001];
int done[1001][1001][2];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int N, M;

typedef struct position
{
	int x;
	int y;
	int crash;
} pos;

queue<pos> q;

int bfs()
{
	int curx, cury;

	done[0][0][0] = 1;
	q.push({0, 0, 0});

	while (!q.empty())
	{
		pos cur = q.front();
		q.pop();

		if (cur.x == M - 1 && cur.y == N - 1)
			return (done[cur.y][cur.x][cur.crash]);

		for (int i = 0; i < 4; i++)
		{
			curx = cur.x + dx[i];
			cury = cur.y + dy[i];
			if (curx < 0 || curx >= M || cury < 0 || cury >= N)
				continue;
			if (done[cury][curx][cur.crash])
				continue;
			if (map[cury][curx] == '0')
			{
				q.push({curx, cury, cur.crash});
				done[cury][curx][cur.crash] = done[cur.y][cur.x][cur.crash] + 1;
			}
			else if (map[cury][curx] == '1' && cur.crash == 0)
			{
				q.push({curx, cury, 1});
				done[cury][curx][1] = done[cur.y][cur.x][cur.crash] + 1;
			}
		}
	}
	return (-1);
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> map[i];

	cout << bfs();
	return 0;
}

