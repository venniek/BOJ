class Solution {
    func fib(_ n: Int) -> Int {
        var dp = [Int](repeating: 0, count: n + 1)
        
        dp[0] = 0
        if n > 0 {
            dp[1] = 1
            if n > 1 {
                for i in 2...n {
                    dp[i] = dp[i - 1] + dp[i - 2]
                }
            }
        }
        return dp[n]
    }
}
