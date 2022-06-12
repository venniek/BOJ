#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int ans = 0;

int cmp(vector<int> &a, vector<int>  &b) {
    return (a[0] - a[1]) > (b[0] - b[1]);
}

void find_max(int k, vector<vector<int> > &dungeons, int idx, int cnt) {
    if (idx == dungeons.size()) {
        ans = max(ans, cnt);
        return ;
    }
    find_max(k, dungeons, idx + 1, cnt);
    if (k >= dungeons[idx][0])
        find_max(k - dungeons[idx][1], dungeons, idx + 1, cnt + 1);
}

int solution(int k, vector<vector<int>> dungeons) {
    sort(dungeons.begin(), dungeons.end(), cmp);
    find_max(k, dungeons, 1, 0);
    if (k >= dungeons[0][0])
        find_max(k - dungeons[0][1], dungeons, 1, 1);
    return ans;
}
