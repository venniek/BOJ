class Solution {
    func countAlpha(_ s: String) -> [Int] {
        var ret = [Int](repeating: 0, count: 26)
        for c in s {
            ret[Int(c.asciiValue! - 97)] += 1
        }
        return ret
    }
    
    func checkInclusion(_ s1: String, _ s2: String) -> Bool {
        let len1 = s1.count
        let len2 = s2.count
        if len1 > len2 { return false }
        let forS1 = countAlpha(s1)
        var forS2 = countAlpha(String(s2.prefix(len1)))
        for i in 0...len2 - len1 {
            if forS1 == forS2 {
                return true
            } else if i == len2 - len1 {
                return false
            } else {
                forS2[Int(s2[s2.index(s2.startIndex, offsetBy: i)].asciiValue! - 97)] -= 1
                forS2[Int(s2[s2.index(s2.startIndex, offsetBy: i + len1)].asciiValue! - 97)] += 1
            }
        }
        return false
    }
}

