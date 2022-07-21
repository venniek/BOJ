class Solution {
    func generate(_ numRows: Int) -> [[Int]] {
        var ret = [[Int]]()
        for i in 1...numRows {
            var tmp = [Int](repeating: 0, count: i)
            for k in 0..<i {
                if k == 0 || k == i - 1 {
                    tmp[k] = 1
                } else {
                    tmp[k] = ret[i - 2][k - 1] + ret[i - 2][k]
                }
            }
            ret.append(tmp)
        }
        return ret
    }
}
