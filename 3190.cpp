#include <iostream>
#include <queue>
#include <deque>
#include <utility>
using namespace std;
int N, k ,L, X;
char C;
int map[102][102];
queue<pair<int, char> > rot;
deque<pair<int, int> > s;
int vec = 1;

void to_go(int *x, int *y)
{
	*x = 0;
	*y = 0;
    if (vec == 1)
		*x = 1;
	else if (vec == 3)
		*x = -1;
	else if (vec == 2)
		*y = 1;
	else
		*y = -1;
}

void change_vec(char c)
{
	if (c == 'D')
		vec++;
	else if (c == 'L')
		vec--;
	if (vec == 5)
		vec = 1;
	if (vec == 0)
		vec = 4;
}

int main()
{
    int time = 0;
	int x, y;
	int px, py;
	cin >> N >> k;
	for (int i = 0; i <= N + 1; i++)
		for (int k = 0; k <= N + 1; k++)
			if (i == 0 || i == N + 1 || k == 0 || k == N + 1)
				map[i][k] = 2;
    while (k--)
    {
        cin >> y >> x;
        map[y][x] = 1;
    }
    cin >> L;
    while (L--)
    {
        cin >> X >> C;
		rot.push(make_pair(X, C));
    }
	s.push_back({1,1});
    map[1][1] = 2;
	while (++time)
	{
		to_go(&px, &py);
        if (map[s.front().second + py][s.front().first + px] == 2)
		{
            cout << time;
            return 0;
        }
		s.push_front(make_pair(s.front().first + px, s.front().second + py));
		if (map[s.front().second][s.front().first] != 1)
		{
			map[s.back().second][s.back().first] = 0;
			s.pop_back();
        }
		map[s.front().second][s.front().first] = 2;
		if (time == rot.front().first)
		{
			change_vec(rot.front().second);
			rot.pop();
		}
	}
}
