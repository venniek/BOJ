class Solution {
    func isPalindrome(_ s: String) -> Bool {
        let str = Array(s.lowercased())
        var start = 0
        var end = s.count - 1
        
        while start <= end {
            let st = str[start], en = str[end]
            if !(st.isNumber || st.isLetter) {
                start += 1
            } else if !(en.isNumber || en.isLetter) {
                end -= 1
            } else if st != en {
                return false
            } else {
                start += 1
                end -= 1
            }
        }
        return true
    }
}
