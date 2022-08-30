#include <iostream>
using namespace std;

int main() {
    int n;
    long long dp[1000005] = {0, };
    long long sum = 0;
    cin >> n;
    
    dp[0] = 1;
    dp[1] = 2;
    dp[2] = 7;
    dp[3] = 22;
    sum = 32;
    for (int i = 4; i <= n; i++) {
        dp[i] = (sum * 2 + dp[i - 2]) % 1000000007;
        sum += dp[i];
        sum %= 1000000007;
    }
    cout << dp[n];
    return 0;
}