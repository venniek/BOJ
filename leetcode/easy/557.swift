class Solution {
    func reverseWords(_ s: String) -> String {
        var strs = s.components(separatedBy: " ")
        var ret = String()
        for str in strs {
            ret += String(str.reversed()) + " "
        }
        ret = String(ret.dropLast())
        return ret
    }
}
