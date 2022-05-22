#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 위 0 오 1 아 2 왼 3
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
int used[505][505][4];
vector<string> map;
int row, col;

int check_cycle(int i, int k, int j, int cnt) {
    if (used[i][k][j] == 1)
        return cnt;
	used[i][k][j] = 1;
    if (map[i][k] != 'S')
    	j = (map[i][k] == 'L' ? (j - 1 < 0 ? 3 : j - 1) : (j + 1) % 4); 
	i = i + dy[j] < 0 ? row - 1 : (i + dy[j] >= row ? 0 : i + dy[j]);
	k = k + dx[j] < 0 ? col - 1 : (k + dx[j] >= col ? 0 : k + dx[j]);
    return check_cycle(i, k, j, cnt + 1);
}

vector<int> solution(vector<string> grid) {
	vector<int> answer;
    int tmp;
	map = grid;
	row = map.size();
	col = map[0].size();
    
	for (int i = 0; i < row; i++) {
		for (int k = 0; k < col; k++) {
			for (int j = 0; j < 4; j++) {
				tmp = check_cycle(i, k, j, 0);
				if (tmp != 0)
					answer.push_back(tmp);
			}
		}
	}
    sort(answer.begin(), answer.end());
	return answer;
}
