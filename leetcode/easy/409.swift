class Solution {
    func longestPalindrome(_ s: String) -> Int {
        let str = Array(s)
        var dict = [Character:Int]()
        var ans = 0
        
        for c in str {
            if let val = dict[c] {
                dict[c] = val + 1
            } else {
                dict[c] = 1
            }
        }
        var flag = 0
        for (key, value) in dict {
            if value % 2 == 1 {
                if flag == 0 {
                    ans += value
                    flag = 1
                } else {
                    ans += value - 1
                }
            } else {
                ans += value
            }
        }
        return ans
    }
}
