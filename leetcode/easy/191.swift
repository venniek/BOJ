class Solution {
    func hammingWeight(_ n: Int) -> Int {
        var cn = n
        var ans = 0
        
        while cn > 0 {
            ans += cn & 1
            cn >>= 1
        }
        return ans
    }
}
