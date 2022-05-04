#include <string>
#include <vector>
#include <algorithm>
using namespace std;


int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    vector<string> v;

    if (cacheSize == 0)
        return cities.size() * 5;
    for (string c : cities) {
        for (int i = 0; i < c.size(); i++) c[i] = toupper(c[i]);
        if (find(v.begin(), v.end(), c) == v.end()) {
            answer += 5;
            if (v.size() == cacheSize)
                v.erase(v.begin());
        } else {
            answer += 1;
            v.erase(find(v.begin(), v.end(), c));
        }
        v.push_back(c);
    }
    return answer;
}