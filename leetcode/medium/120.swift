class Solution {
    func minimumTotal(_ triangle: [[Int]]) -> Int {
        let height = triangle.count
        var dp = [[Int]](repeating: [Int](repeating: 100000, count: height), count: height)
        var ans = 100000
        dp[0][0] = triangle[0][0]
        for i in 1..<height {
            for j in 0...i {
                dp[i][j] = (j == 0 ? dp[i - 1][j] : min(dp[i - 1][j - 1], dp[i - 1][j])) + triangle[i][j]
            }
        }
        for i in 0..<height {
            ans = min(ans, dp[height - 1][i])
        }
        return ans
    }
}
