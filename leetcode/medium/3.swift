class Solution {
    func lengthOfLongestSubstring(_ s: String) -> Int {
        var left = 0, right = 1
        var alpha = [Character: Int]()
        var ans = 0
        let str = Array(s)
        
        if s.count <= 1 {
            return s.count
        }
        alpha[str[0]] = 0
        while right != str.count {
            if let tmp = alpha[str[right]] {
                for (key, value) in alpha {
                    if value <= tmp {
                        alpha[key] = nil
                    }
                }
                left = tmp + 1
            }
            alpha[str[right]] = right
            ans = max(ans, right - left + 1)
            right += 1
        }
        return ans
    }
}
