#include <string>
#include <vector>
#include <iostream>
#include <set>
#define PII pair<int, int>
using namespace std;

int startx, starty, endx, endy;
int dx[8] = {0, -1, -1, 1, 1, -1, 0, 1};
int dy[8] = {1, -1, 0, -1, 0, 1, -1, 1};
set<pair<PII, PII> > line;
int map[55][55];
int ans = 1e5;

bool check_edge(int x, int y, int nx, int ny) {
	for (int i = 0; i < 8; i++) {
		if (map[ny + dy[i]][nx + dx[i]] == 0) {
			
		}
	}
	if (line.find({{x, y}, {nx, ny}}) != line.end())
		return true;
	return false;
}

void add_map(int x1, int y1, int x2, int y2) {
	for (int i = y1; i <= y2; i++) {
		for (int j = x1; j <= x2; j++) {
			map[i][j] = 1;
		}
	}
	for (int i = 0; y1 + i <= y2; i++) {
		for (int j = 0; x1 + j <= x2; j++) {
			if (j == 0 || j == x2 - x1) {
				line.insert({{x1, y1 + i}, {x1, y1 + i + 1}});
				line.insert({{x1, y1 + i + 1}, {x1, y1 + i}});
				line.insert({{x2, y1 + i}, {x2, y1 + i + 1}});
				line.insert({{x2, y1 + i + 1}, {x2, y1 + i}});
			}
			else {
				line.insert({{x1 + j, y1}, {x1 + j + 1, y1}});
				line.insert({{x1 + j + 1, y1}, {x1 + j, y1}});
				line.insert({{x1 + j, y2}, {x1 + j + 1, y2}});
				line.insert({{x1 + j + 1, y2}, {x1 + j, y2}});
			}
		}
	}
}

void find_ans(int x, int y, int now) {
	if (x == endx && y == endy) {
		cout << "this is end. now+1 is " << now + 1 << endl;
		ans = min(ans, now + 1);
		map[y][x] = 1;
		return ;
	}
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i * 2];
		int ny = y + dy[i * 2];
		if (map[ny][nx] == 1 && check_edge(x, y, nx, ny)) {
			map[ny][nx] = 2;
			find_ans(nx, ny, now + 1);
			if (!(x == startx & y == starty))
				return ;
		}
	}
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
	startx = characterX; starty = characterY;
	endx = itemX; endy = itemY;

	for (vector<int> v: rectangle)
		add_map(v[0], v[1], v[2], v[3]);
	map[starty][startx] = 2;
	find_ans(startx, starty, 0);
	return ans;
}

int main() {
	vector<vector<int> > rectangle;
	vector<int> tmp;

	tmp.push_back(1);
	tmp.push_back(1);
	tmp.push_back(7);
	tmp.push_back(4);
	rectangle.push_back(tmp);
	tmp.clear();
	
	tmp.push_back(3);
	tmp.push_back(2);
	tmp.push_back(5);
	tmp.push_back(5);
	rectangle.push_back(tmp);
	tmp.clear();

	tmp.push_back(4);
	tmp.push_back(3);
	tmp.push_back(6);
	tmp.push_back(9);
	rectangle.push_back(tmp);
	tmp.clear();

	tmp.push_back(2);
	tmp.push_back(6);
	tmp.push_back(8);
	tmp.push_back(8);
	rectangle.push_back(tmp);
	tmp.clear();

	cout << "ans: " << endl;
	cout << solution(rectangle, 1, 3, 7, 8) << endl;
	return 0;
}