class Solution {
    func generate(_ numRows: Int) -> [[Int]] {
        var ans = [[Int]](repeating: [Int](repeating: 0, count: numRows), count: numRows)
        
        for i in 0..<numRows {
            for j in 0...i {
                if j == 0 || i == j {
                    ans[i][j] = 1
                } else {
                    ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j]
                }
            }
            ans[i] = Array(ans[i][0...i])
        }
        return ans
    }
}
