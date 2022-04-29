#include <iostream>
#include <string>

using namespace std;

int ans[5005][2];

int main() {
    string p;

    cin >> p;
    if (p[0] == '0') {
        cout << 0;
        return 0;
    }
    ans[0][0] = 1;
    ans[0][1] = 0;
    for (int i = 1; i < p.size(); i++) {
        ans[i][0] = p[i] == '0' ? 0 : ans[i - 1][0] + ans[i - 1][1];
        int tmp = stoi(p.substr(i - 1, 2));
        if (tmp >= 10 && tmp <= 26)
            ans[i][1] = ans[i - 1][0];
        else if (p[i] == '0') {
            cout << 0;
            return 0;
        }
        ans[i][0] %= 1000000;
        ans[i][1] %= 1000000;
    }
    cout << (ans[p.size() - 1][0] + ans[p.size() - 1][1]) % 1000000;
}