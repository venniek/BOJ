#include <vector>
#include <queue>
#include <utility>
#define PIII pair< pair<int, int>, int >
using namespace std;

int solution(vector<vector<int> > maps) {
    queue<PIII> q;
    int row = maps.size();
    int col = maps[0].size();
    int ans = 50000;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    q.push({{0, 0}, 1});
    while (!q.empty()) {
        PIII now = q.front();
        q.pop();
        if (now.first.second == row - 1 && now.first.first == col - 1)
            return now.second;
        for (int i = 0; i < 4; i++) {
            int nr = now.first.second + dy[i];
            int nc = now.first.first + dx[i];
            if (nr < 0 || nr >= row || nc < 0 || nc >= col) continue;
            if (maps[nr][nc] == 1) {
                maps[nr][nc] = 3;
                q.push({{nc, nr}, now.second + 1});
            }
        }        
    }
    return -1;
}
