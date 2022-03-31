#include <string>
#include <sstream>
using namespace std;

int get_score(char c, int score) {
    if (c == 'S')
        return score;
    if (c == 'D')
        return score * score;
    return score * score * score;
}

int solution(string dartResult) {
    int answer = 0;
    stringstream ss(dartResult);
    int score[3];
    char opt[3];
    char tmp;

    for (int i = 0; i < 3; i++) {
        ss >> score[i];
        ss >> opt[i];
        score[i] = get_score(opt[i], score[i]);
        if ((tmp = ss.get()) == '*' || tmp == '#') {
            if (tmp == '*') {
                for (int j = max(0, i - 1); j <= i; j++)
                    score[j] *= 2;
            }
            else
                score[i] *= -1;
        }
        else
            ss.unget();
    }
    for (int i = 0; i < 3; i++)
        answer += score[i];
    return answer;
}
