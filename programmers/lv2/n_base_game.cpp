#include <string>
#include <vector>
#include <algorithm>
using namespace std;

char tos(int i) {
    return i + (i < 10 ? '0' : -10 + 'A');
}

string convert_n(int cnt, int n) {
    string tmp;
    
    if (cnt == 0)
        return "0";
    while (cnt > 0) {
        tmp += tos(cnt % n);
        cnt /= n;
    }
    reverse(tmp.begin(), tmp.end());
    return tmp;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    string tmp = "";
    int cnt = 0;
    
    while (tmp.size() <= m * t) {
        tmp += convert_n(cnt, n);
        cnt++;
    }
    for (int i = 0; i < t; i++) {
        answer += tmp[i * m + p - 1];
    }
    return answer;
}
