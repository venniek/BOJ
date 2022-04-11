#include <iostream>
#include <stack>
#include <string>
using namespace std;

int done[35];
int ans;

int check_s(string s) {
    stack<char> st;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(' || s[i] == '[')
            st.push(s[i]);
        else {
            if (!st.empty() && ((st.top() == '[' && s[i] == ']') || (st.top() == '(' && s[i] == ')')))
                st.pop();
            else
                return 1;
        }
    }
    if (st.empty() != 1)
        return 1;
    return 0;
}

int cal_s(string s, int idx, int now) {
    for (int i = idx; i < s.size(); i++) {
        if (done[i])
            continue;
        done[i] = 1;
        if (s[i] == '(')
            now += 2 * cal_s(s, i + 1, 0);
        else if (s[i] == '[')
            now += 3 * cal_s(s, i + 1, 0);
        else
            break;
    }
    return max(1, now);
}

int main() {
    string s;

    cin >> s;
    if (check_s(s) == 1) {
        cout << 0 << endl;
        return 0;
    }
    cout << cal_s(s, 0, 0) << endl;
    return 0;
}