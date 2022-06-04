#include <string>
#include <vector>
#include <set>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    set<string> m;
    char c;
    
    for (int i = 0; i < words.size(); i++) {
        string tmp = words[i];
        if (tmp.size() == 1 || m.find(tmp) != m.end() || (i != 0 && tmp[0] != c))
            return {i % n + 1, i / n + 1};
        m.insert(words[i]);
        c = tmp[tmp.size() - 1];
    }

    return {0, 0};
}
