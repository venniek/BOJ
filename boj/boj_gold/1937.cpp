#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

typedef struct xy
{
    int value;
    int x;
    int y;
} xy;

int board[505][505];
int origin[505][505];
int n;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
bool compare(xy p1, xy p2)
{
    if (p1.value > p2.value)
    {
        return true;
    }
    return false;
}

int main()
{
    vector<xy> xys;
    int tmp;

    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> origin[i][j];
            xys.push_back({origin[i][j], i, j});
        }
    sort(xys.begin(), xys.end(), compare);

    for (int i = 0; i < n * n; i++)
    {
        int nx = xys[i].x;
        int ny = xys[i].y;
        int mx = 0;
        for (int j = 0; j < 4; j++)
        {
            if (nx + dx[j] <= 0 || ny + dy[j] <= 0 || nx + dx[j] > n || ny + dy[j] > n)
                continue;
			if (xys[i].value < origin[nx + dx[j]][ny + dy[j]])
	            mx = max(mx, board[nx + dx[j]][ny + dy[j]]);
        }
        board[nx][ny] = mx + 1;
    }
	int mx = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            mx = max(mx, board[i][j]);
	cout << mx;
}