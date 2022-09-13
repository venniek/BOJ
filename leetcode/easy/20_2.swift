class Solution {
    func isValid(_ s: String) -> Bool {
        var st = [Character]()
        let m: [Character: Character] = ["(": ")", "[": "]", "{": "}"]
        
        for c in s {
            if let _ = m[c] {
                st.append(c)
            } else if st.isEmpty {
                return false
            } else if m[st[st.count - 1]]! == c {
                st.popLast()
            } else {
                return false
            }
        }
        return st.count == 0
    }
}
