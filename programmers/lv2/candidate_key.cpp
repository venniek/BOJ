#include <string>
#include <vector>
#include <iostream>
#include <set>
using namespace std;

int is_right_key(vector<vector<string>> rel, string num) {
    set<string> strs;
    
    for (int i = 0; i < rel.size(); i++) {
        string tmp = "";
        for (int k = 0; k < num.size(); k++) {
            tmp += rel[i][num[k] - '0'];
        }
        strs.insert(tmp);
    }
    if (strs.size() == rel.size())
        return 1;
    return 0;
}

int solution(vector<vector<string>> relation) {
    vector<string> key;
    int n = relation[0].size();
    
    for (int i = 0; i < (1 << n); i++) {
        string num = "";
        for (int j = 0; j < n; ++j)
            if (i & (1 << j))
                num += j + '0';
        if (is_right_key(relation, num))
            key.push_back(num);
    }
    for (int i = 0; i < key.size() - 1; i++) {
        for (int k = i + 1; k < key.size(); k++) {
            int j = 0;
            for (j; j < key[i].size(); j++) {
                if (key[k].find(key[i][j]) == string::npos)
                    break;
            }
            if (j == key[i].size()) {
                key.erase(key.begin() + k);
                k--;
            }
        }
    }
    return key.size();
}