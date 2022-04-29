#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
using namespace std;

string make_alpha(vector<string> orders) {
    string ret;
    set<int> alpha;
    
    for (int i = 0; i < orders.size(); i++)
        for (int j = 0; j < orders[i].size(); j++)
            alpha.insert(orders[i][j] - 'A');
	for (auto it : alpha)
		ret += it + 'A';
    return ret;
}

int is_right(string big, string temp) {
    int right = 0;
    
    sort(big.begin(), big.end());
    int bi = 0;
    int ti = 0;
    while (ti < temp.size() && bi < big.size()) {
        if (temp[ti] == big[bi]) {
            right++;
            ti++;
        }
        bi++;
    }
    if (right == temp.size())
        return 1;
    return 0;
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    string alpha = make_alpha(orders);
    int len = alpha.size();
    
    for (int i = 1; i <= len; i++) {
        if (course.empty() || i != course[0])
            continue;
        course.erase(course.begin());
        vector<string> anstmp;
        int maxcnt = 0;
        vector<bool> v(len - i, false);
        v.insert(v.end(), i, true);
        do {        // 조합 찾아서 order 하나씩 비교
            string temp = "";
            for (int k = 0; k < len; k++)
                if (v[k]) temp += alpha[k];
            int cnt = 0;
            for (int k = 0; k < orders.size(); k++)
                cnt += is_right(orders[k], temp);
            if (cnt >= 2) {
                if (cnt > maxcnt) {
                    anstmp.clear();
                    anstmp.push_back(temp);
                    maxcnt = cnt;
                }
                else if (cnt == maxcnt)
                    anstmp.push_back(temp);
            }
        } while (next_permutation(v.begin(), v.end()));
        for (int k = 0; k < anstmp.size(); k++)
            answer.push_back(anstmp[k]);
	}
    sort(answer.begin(), answer.end());
    return answer;
}