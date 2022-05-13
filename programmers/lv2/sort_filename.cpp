#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#define SISI pair<pair<string, int>, int>
using namespace std;

int cmp(SISI &a, SISI &b) {
    if (a.first.first == b.first.first) {
        if (a.first.second == b.first.second) {
            return a.second < b.second;
        }
        return a.first.second < b.first.second;
    }
    return a.first.first < b.first.first;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<SISI> info;
    
    for (int k = 0; k < files.size(); k++) {
        string str = files[k];
        string head, num;
        int i = 0;
        for (; str[i] && !(str[i] >= '0' && str[i] <= '9'); i++)
            head += toupper(str[i]);
        for (; str[i] && str[i] >= '0' && str[i] <= '9'; i++)
            num += str[i];
        info.push_back({{head, stoi(num)}, k});
    }
    sort(info.begin(), info.end(), cmp);
    for (SISI in : info)
        answer.push_back(files[in.second]);
    return answer;
}
