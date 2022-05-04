#include <string>
#include <vector>
#include <utility>
#define PII pair<int, int>
using namespace std;

void go(PII& from, PII to, string& answer, int i) {
    from = to;
    answer += i == 0 ? "R" : "L";
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    PII left = make_pair(3, 0);
    PII right = make_pair(3, 2);
    for (int n: numbers) {
        if (n == 0) n = 11;
        PII tmp = make_pair((n - 1) / 3, (n - 1) % 3);
        if (tmp.second == 2)
            go(right, tmp, answer, 0);
        else if (tmp.second == 0)
            go(left, tmp, answer, 1);
        else {
            int diff = (abs(tmp.first - left.first) + abs(tmp.second - left.second)) 
                - (abs(tmp.first - right.first) + abs(tmp.second - right.second));
            if (diff > 0)
                go(right, tmp, answer, 0);
            else if (diff < 0)
                go(left, tmp, answer, 1);
            else {
                if (hand == "right")
                    go(right, tmp, answer, 0);
                else
                    go(left, tmp, answer, 1);
            }
        }
    }
    return answer;
}