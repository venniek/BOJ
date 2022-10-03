func solution(_ n:Int) -> Int {
    var dp = [Int](repeating: 0, count: n + 10)
    
    dp[1] = 1
    dp[2] = 2
    if n <= 2 {
        return dp[n]
    }
    for i in 3...n {
        dp[i] = (dp[i - 2] + dp[i - 1]) % 1234567
    }
    return dp[n]
}
