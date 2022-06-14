#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> words;
string vw[5] = {"A", "E", "I", "O", "U"};

void dfs(string str, int now, int len) {
    if (now == len) {
        words.push_back(str);
        return ;
    }
    for (int i = 0; i < 5; i++)
        dfs(str + vw[i], now + 1, len);
}

int solution(string word) {
    for (int i = 1; i <= 5; i++)
        dfs("", 0, i);
    sort(words.begin(), words.end());
    return find(words.begin(), words.end(), word) - words.begin() + 1;
}