#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long answer = 0;
int visited[300000];

void dfs(vector<long long> &vt, vector<vector<int> > &map, int parent) {
    visited[parent] = 1;
    for (int i = 0; i < map[parent].size(); i++) {
        if (visited[map[parent][i]]) continue;
        dfs(vt, map, map[parent][i]);
        answer += abs(vt[map[parent][i]]);
        vt[parent] += vt[map[parent][i]];
    }
}

long long solution(vector<int> a, vector<vector<int> > edges) {
    vector<long long> vt(a.begin(), a.end());
    vector<vector<int> > map(a.size());

    for (vector<int> v: edges) {
        map[v[0]].push_back(v[1]);
        map[v[1]].push_back(v[0]);
    }
    dfs(vt, map, 0);    
    return vt[0] != 0 ? -1 : answer;
}