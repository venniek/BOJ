#include <string>
#include <vector>
using namespace std;

vector<string> solution(vector<string> s) {
    vector<string> answer;
    
    for (string str: s) {
        string tmp;
        string plus;
        size_t n;
        for (char c: str) {
            if (c == '0' && tmp.size() >= 2 && tmp.substr(tmp.size() - 2, 2) == "11") {
                tmp.erase(tmp.size() - 2, 2);
                plus += "110";
            }
            else
                tmp += c;
        }
        if ((n = tmp.rfind("0")) != string::npos)
            tmp.insert(n + 1, plus);
        else
            tmp.insert(0, plus);
        answer.push_back(tmp);
    }
    return answer;
}