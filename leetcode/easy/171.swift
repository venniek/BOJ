class Solution {
    func titleToNumber(_ columnTitle: String) -> Int {
        var ans = 0
        var cnt = columnTitle.count - 1
        for c in columnTitle {
            ans += (Int(c.asciiValue!) - 64) * Int(pow(Double(26), Double(cnt)))
            cnt -= 1
        }
        return ans
    }
}
