class Solution {
    func matrixReshape(_ mat: [[Int]], _ r: Int, _ c: Int) -> [[Int]] {
        let row = mat.count
        let col = mat[0].count
        var ret = [[Int]](repeating: [Int](repeating: 0, count: c), count: r)
        if row * col != r * c { return mat }
        var newr = 0
        var newc = 0
        for i in 0..<row {
            for k in 0..<col {
                ret[newr][newc] = mat[i][k]
                newc += 1
                if newc == c {
                    newc = 0
                    newr += 1
                }
            }
        }
        return ret
    }
}
