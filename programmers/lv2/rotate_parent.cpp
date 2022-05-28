#include <string>
#include <vector>
#include <stack>
using namespace std;

stack<char> st;

int match(char a, char b) {
    if (a == '{' && b == '}')
        return 1;
    if (a == '[' && b == ']')
        return 1;
    if (a == '(' && b == ')')
        return 1;
    return 0;
}

int solution(string s) {
    int answer = 0;
    int len = s.size();
    
    for (int i = 0; i < len; i++) {
        int right = 1;
        for (int k = 0; k < len; k++) {
            if (s[k] == '[' || s[k] == '{' || s[k] == '(')
                st.push(s[k]);
            else if (s[k] == ']' || s[k] == '}' || s[k] == ')') {
                if (st.empty() || match(st.top(), s[k]) == 0) {
                    right = 0;
                    break;
                }
                else
                    st.pop();
            }
        }
        if (right == 1 && st.empty())
            answer++;
        s += s[0];
        s.erase(0, 1);
    }
    return answer;
}
