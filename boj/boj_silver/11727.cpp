#include <iostream>
using namespace std;

int main() {
    int ans[1001];
    int n;
    
    cin >> n;
    ans[1] = 1;
    ans[2] = 3;
    for (int i = 3; i <= n; i++)
        ans[i] = (ans[i - 1] + ans[i - 2] * 2) % 10007;
    cout << ans[n];
}