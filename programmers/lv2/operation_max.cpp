#include <string>
#include <vector>
#include <math.h>
#define LL long long
using namespace std;

LL cal(LL a, LL b, char c) {
    if (c == '*')
        return a * b;
    if (c == '+')
        return a + b;
    if (c == '-')
        return a - b;
}

void make_sum(vector<LL> num, vector<char> oper, string prio, LL &sum) {
    for (int i = 0; i < 3; i++) {
        for (int k = 0; k < oper.size(); k++) {
            if (oper[k] == prio[i]) {
                num[k] = cal(num[k], num[k + 1], oper[k]);
                num.erase(num.begin() + k + 1);
                oper.erase(oper.begin() + k);
                k--;
            }
        }
    }
    sum = max(sum, abs(num[0]));
}

LL solution(string expression) {
    LL sum = 0;
    vector<LL> num;
    vector<char> oper;
    string prio[6] = { "*+-", "*-+", "+-*", "+*-", "-+*", "-*+" };
    
    for (int i = 0; i < expression.size(); i++) {
        string tmp;
        while (expression[i] && expression[i] >= '0' && expression[i] <= '9')
            tmp += expression[i++];
        num.push_back(stoi(tmp));
        if (i != expression.size())
            oper.push_back(expression[i]);
    }
    for (int i = 0; i < 6; i++)
        make_sum(num, oper, prio[i], sum);
    return sum;
}
