class Solution {
    func uniquePaths(_ m: Int, _ n: Int) -> Int {
        var map = [[Int]](repeating: [Int](repeating: 0, count: n), count: m)
        
        for i in 0..<m {
            for j in 0..<n {
                if i == 0 || j == 0 {
                    map[i][j] = 1          
                } else {
                    map[i][j] = map[i - 1][j] + map[i][j - 1]
                }
            }
        }
        return map[m - 1][n - 1]
    }
}
