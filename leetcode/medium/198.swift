class Solution {
    func rob(_ nums: [Int]) -> Int {
        var dp = [[Int]](repeating: [Int](repeating: 0, count: 2), count: nums.count)
        dp[0][0] = 0
        dp[0][1] = nums[0]
        if nums.count > 1  {
            dp[1][0] = nums[0]
            dp[1][1] = nums[1]
            for i in 2..<nums.count {
                dp[i][0] = max(dp[i - 1][0], dp[i - 1][1])
                dp[i][1] = max(dp[i - 2][1], dp[i - 1][0]) + nums[i]
            }
        }
        return max(dp[nums.count - 1][0], dp[nums.count - 1][1])
    }
}
