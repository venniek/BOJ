class Solution {
    func reverseString(_ s: inout [Character]) {
        for i in 0..<s.count / 2 {
            let tmp = s[i]
            s[i] = s[s.count - i - 1]
            s[s.count - i - 1] = tmp
        }
    }
}
