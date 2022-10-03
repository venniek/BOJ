class Solution {
    func isHappy(_ n: Int) -> Bool {
        var s = Set<Int>()
        var cn = n
        while cn != 1 {
            s.insert(cn)
            var tmp = 0
            while cn > 0 {
                tmp += (cn % 10) * (cn % 10)
                cn /= 10
            }
            if s.contains(tmp) {
                return false
            }
            cn = tmp
        }
        return true
    }
}
