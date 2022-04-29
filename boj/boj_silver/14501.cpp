#include <iostream>
using namespace std;

int ans[16][2]; // 0: 했을 때  1: 안 했을 때
int t[16];
int p[16];

int main() {
    int n;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t[i] >> p[i];
        if (t[i] > n - i)
            p[i] = 0;
    }
    ans[0][0] = p[0];
    for (int i = 1; i < n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (j + t[j] <= i) {
                ans[i][0] = max(ans[i][0], ans[j][0]);
            }
        }
        ans[i][0] += p[i];
        ans[i][1] = max(ans[i - 1][0], ans[i - 1][1]);
    }
    cout << max(ans[n - 1][0], ans[n - 1][1]);
}