#include <string>
#include <vector>

using namespace std;

string toBinary(int n) {
    string r;
    while (n != 0) {
        r += ( n % 2 == 0 ? "0" : "1" );
        n /= 2;
    }
    return r;
}

vector<int> solution(string s) {
    vector<int> answer;
    int repeat = 0;
    int zero = 0;
    
    while (s != "1") {
        int cnt = 0;
        for (char c: s)
            if (c == '1') cnt++;
        zero += s.size() - cnt;
        s = toBinary(cnt);
        repeat++;
    }
    answer.push_back(repeat);
    answer.push_back(zero);
    return answer;
}
