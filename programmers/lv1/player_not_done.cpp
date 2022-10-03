#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> p, vector<string> completion) {
    sort(p.begin(), p.end());
    sort(completion.begin(), completion.end());
    for (int i = 0; i < completion.size(); i++) {
        if (p[i] != completion[i])
            return p[i];
    }
    return p[p.size() - 1];
}
