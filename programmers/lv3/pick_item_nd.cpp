#include <vector>
using namespace std;

// 0 위 1 오른 2 아래 3 왼
int map[55][55];
int done[55][55];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int ans = 1e5;

bool check_edge(int x, int y, int dir) {
	int x1, x2, y1, y2;
	if (dir % 2 == 0)
		return map[y - dir / 2][x - 1] + map[y - dir / 2][x] == 1;
	return map[y][x - dir / 2] + map[y - 1][x - dir / 2] == 1;
}

void find_ans(int x, int y, int &endX, int &endY, int cnt) {
	if (x == endX && y == endY) {
		done[y][x] = 0;
		ans = min(ans, cnt);
		return ;
	}
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (done[ny][nx] == 0 && check_edge(x, y, i)) {
			done[ny][nx] = 1;
			find_ans(nx, ny, endX, endY, cnt + 1);
		}
	}
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
	for (vector<int> v: rectangle) {
		for (int i = v[1]; i < v[3]; i++) {
			for (int j = v[0]; j < v[2]; j++)
				map[i][j]++;
		}
	}
	done[characterY][characterX] = 1;
	find_ans(characterX, characterY, itemX, itemY, 0);
	return ans;
}