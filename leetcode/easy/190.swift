class Solution {
    func reverseBits(_ n: Int) -> Int {
        var ans = 0
        var cn = n
        var idx = 30
        
        while cn > 0 {
            ans += (cn & 1) * (2 << idx)
            idx -= 1
            cn >>= 1
        }
        return ans
    }
}
