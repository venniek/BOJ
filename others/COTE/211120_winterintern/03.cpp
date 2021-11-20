#include <string>
#include <vector>
#include <map>
#include <queue>
using namespace std;
int cake[105][105];
int visited[105][105];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

queue<pair<int, int> > q;

int solution(vector<string> cakes, vector<int> cut_rows, vector<int> cut_columns)
{
	int answer = 0;
	int n = cakes.size() * 2 - 1;

	for (int i = 1; i <= n; i += 2)
		for (int j = 1; j <= n; j += 2)
			cake[i][j] = cakes[i][j] - 'A' + 1;
	for (int i = 0; i < cut_rows.size(); i++)
		for (int j = 1; j <= n; j += 2)
			cake[cut_rows[i]][j] = 1;
	for (int i = 0; i < cut_columns.size(); i++)
		for (int j = 1; j <= n; j += 2)
			cake[j][cut_columns[i]] = 1;
	for (int i = 1; i <= n; i += 2)
	{
		for (int j = 1; j <= n; j += 2)
		{
			if (visited[i][j] == 1)
				continue;
			q.push({i, j});
			while (!q.empty())
			{
				pair<int, int> cur = q.front(); q.pop();
				for (int k = 0; k < 4; k++)
				{
					int nx = cur.first + dx[i];
					int ny = cur.second + dy[i];
					if (nx <= 1 || nx > n - 1 || ny <= 1 || ny > n - 1)
						continue;
					if (cake[i][j] == 0)
						continue;
				}
			}
		}
	}

	return answer;
}