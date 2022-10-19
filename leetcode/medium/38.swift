class Solution {
    func countAndSay(_ n: Int) -> String {
        if n == 1 {
            return "1"
        }
        let str = Array(countAndSay(n - 1))
        var ret = ""
        var cnt = 1
        var now = str[0]
        
        for i in 1..<str.count {
            if str[i] != now {
                ret += String(cnt) + String(now)
                cnt = 1
                now = str[i]
            } else {
                cnt += 1
            }
        }
        ret += String(cnt) + String(now)
        return ret
    }
}
