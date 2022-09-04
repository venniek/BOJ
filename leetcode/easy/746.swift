class Solution {
    func minCostClimbingStairs(_ cost: [Int]) -> Int {
        var dp = [Int](repeating: 0, count: cost.count + 1)
        
        dp[0] = cost[0]
        dp[1] = cost[1]
        for i in 2..<cost.count {
            dp[i] = min(dp[i - 2], dp[i - 1]) + cost[i]
        }
        
        return min(dp[cost.count - 1], dp[cost.count - 2])
    }
}
