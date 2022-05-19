#include <string>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int cmp(pair<int, int> &a, pair<int, int> &b) {
    return a.second > b.second;
}

vector<int> solution(string s) {
    int cnt[100005] = {0, };
    vector<pair<int, int> > nums;
    vector<int> answer;
    string tmp;
    
    for (char c : s) {
        if (c >= '0' && c <= '9')
            tmp += c;
        else if (tmp.size()) {
            cnt[stoi(tmp)]++;
            tmp.clear();
        }
    }
    for (int i = 0; i < 100005; i++) {
        if (cnt[i])
            nums.push_back({i, cnt[i]});            
    }
    sort(nums.begin(), nums.end(), cmp);
    for (int i = 0; i < nums.size(); i++)
        answer.push_back(nums[i].first);
    return answer;
}
