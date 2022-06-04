#include <string>
#include <vector>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    for (string str: skill_trees) {
        int fail = 0;
        string::size_type n = 0;
        for (int i = 0; i < skill.size(); i++) {
            string::size_type k;
            if ((k = str.find(skill[i])) != string::npos) {
                if (fail != 0 || k < n) {
                    fail = skill.size() + 1;
                    break;
                }
                n = k;
            }
            else
                fail++;
        }
        if (fail != skill.size() + 1)
            answer++;
    }
    return answer;
}
