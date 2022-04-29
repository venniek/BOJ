#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

int map[101][101];
vector<int> area;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main() {
    int m, n, k;
    int x1, x2, y1, y2;
    queue<pair<int, int> > q;
    cin >> m >> n >> k;
    for (int i = 0; i < k; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        for (int j = x1; j < x2; j++)
            for (int k = y1; k < y2; k++)
                map[k][j] = 1;
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j] == 0) {
                q.push({j, i});
                map[i][j] = 2;
                int tmp = 0;
                while (!q.empty()) {
                    for (int k = 0; k < 4; k++) {
                        int nx = q.front().first + dx[k];
                        int ny = q.front().second + dy[k];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                            continue;
                        if (map[ny][nx] == 0) {
                            q.push({nx, ny});
                            map[ny][nx] = 2;
                        }
                    }
                    q.pop();
                    tmp++;
                }
                area.push_back(tmp);
            }
        }
    }
    sort(area.begin(), area.end());
    cout << area.size() << endl;
    for (int i = 0; i < area.size(); i++) {
        cout << area[i] << " ";
    }
}