#include <string>
#include <vector>
#include <map>
using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    map<char, int> m = {
        {'R', 0}, {'C', 0}, {'J', 0}, {'A', 0}, 
        {'T', 0}, {'F', 0}, {'M', 0}, {'N', 0} 
    };
    
    for (int i = 0; i < choices.size(); i++) {
        int tmp = choices[i];
        if (tmp <= 3)
            m[survey[i][0]] += 4 - tmp;
        else if (tmp >= 5 && tmp <= 7) {
            m[survey[i][1]] += tmp - 4;
        }
    }
    answer += m['R'] >= m['T'] ? "R" : "T";
    answer += m['C'] >= m['F'] ? "C" : "F";
    answer += m['J'] >= m['M'] ? "J" : "M";
    answer += m['A'] >= m['N'] ? "A" : "N";
    return answer;
}
