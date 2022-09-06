class Solution {
    func longestCommonPrefix(_ strs: [String]) -> String {
        var ans = 1
        
        while true {
            let tmp = String(strs[0].prefix(ans))
            for s in strs {
                if s.count < ans {
                    return String(strs[0].prefix(ans - 1))
                }
                if String(s.prefix(ans)) != tmp {
                    return String(s.prefix(ans - 1))
                }
            }
            ans += 1
        }
        return ""
    }
}
