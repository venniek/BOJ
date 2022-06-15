#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int check_chunk(int n, vector<vector<int> > &node) {
    int cnt = 0;
    int done[105] = {0, };
    queue<int> q;
    
    q.push(1);
    while (!q.empty()) {
        int now = q.front();
        q.pop(); ++cnt;
        for (int i : node[now]) {
            if (done[i] == 0)
                q.push(i);
        }
        done[now] = 1;
    }
    return abs(n - cnt * 2);
}

int solution(int n, vector<vector<int>> wires) {
    int ans = n + 1;

    for (int i = 0; i < n - 1; i++) {
        vector<vector<int> > node(n + 1);
        for (int j = 0; j < n - 1; j++) {
            if (j == i) continue;
            int u = wires[j][0];
            int v = wires[j][1];
            node[u].push_back(v);
            node[v].push_back(u);
        }
        ans = min(ans, check_chunk(n, node));
    }
    return ans == n + 1 ? 0 : ans;
}
