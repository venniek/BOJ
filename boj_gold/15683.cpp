#include <iostream>
#include <vector>
using namespace std;

int n, m;
int map[10][10];
int map2[10][10];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int ans = 2147483647;
vector<pair<int, int> > cctv;

int how_many()
{
    int tmp = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (map2[i][j] == 0)
                tmp++;
    return (tmp);
}

int repeat(int num)
{
    if (num == 2)
        return 2;
    if (num == 5)
        return 1;
    return 4;
}

void fill_map2(int x, int y, int i)
{
    while (x + dx[i] >= 0 && x + dx[i] < n && y + dy[i] >= 0 && y + dy[i] < m)
    {
		int nx = x + dx[i];
		int ny = y + dy[i];
        if (map[nx][ny] == 6)
            break;
		if (!(map[nx][ny] >= 1 && map[nx][ny] <= 5))
        	map2[nx][ny] += 7;
		x += dx[i];
		y += dy[i];
	}
}

void make_gamsi(int num, int cnt, int i) // num = cctv 번호, i = cctv 방향(1,2,4) 
{
    int sx = cctv[cnt].first;
    int sy = cctv[cnt].second;

    if (num == 1)
        fill_map2(sx, sy, i);
    else if (num == 2)
    {
        fill_map2(sx, sy, i);
        fill_map2(sx, sy, (i + 2) % 4);
    }
    else if (num == 3)
    {
        fill_map2(sx, sy, i);
        fill_map2(sx, sy, (i + 1) % 4);
    }
    else if (num == 4)
    {
        for (int j = 0; j < 3; j++)
			fill_map2(sx, sy, (i + j) % 4);
    }
    else
    {
		for (int j = 0; j < 4; j++)
			fill_map2(sx, sy, (i + j) % 4);
    }
}

void erase_map2(int x, int y, int i)
{
    while (x + dx[i] >= 0 && x + dx[i] < n && y + dy[i] >= 0 && y + dy[i] < m)
    {
        int nx = x + dx[i];
		int ny = y + dy[i];
        if (map[nx][ny] == 6)
            break;
		if (!(map[nx][ny] >= 1 && map[nx][ny] <= 5))
        	map2[nx][ny] -= 7;
		x += dx[i];
		y += dy[i];
    }
}

void erase_gamsi(int num, int cnt, int i)
{
    int sx = cctv[cnt].first;
    int sy = cctv[cnt].second;

    if (num == 1)
        erase_map2(sx, sy, i);
    else if (num == 2)
    {
        erase_map2(sx, sy, i);
        erase_map2(sx, sy, (i + 2) % 4);
    }
    else if (num == 3)
    {
        erase_map2(sx, sy, i);
        erase_map2(sx, sy, (i + 1) % 4);
    }
    else if (num == 4)
    {
        for (int j = 0; j < 3; j++)
			erase_map2(sx, sy, (i + j) % 4);
    }
    else
    {
		for (int j = 0; j < 4; j++)
			erase_map2(sx, sy, (i + j) % 4);
    }
}

void func(int cnt)
{
    if (cnt == cctv.size())
    {
        ans = min(ans, how_many());
        return;
    }
    int num = map[cctv[cnt].first][cctv[cnt].second];
    for (int i = 0; i < repeat(num); i++)
    {
        make_gamsi(num, cnt, i);
        func(cnt + 1);
        erase_gamsi(num, cnt, i);
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
            if (map[i][j] >= 1 && map[i][j] <= 5)
                cctv.push_back({i, j});
        }
    func(0);
	cout << ans;
    return 0;
}
