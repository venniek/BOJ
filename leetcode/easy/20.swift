class Solution {
    func isValid(_ s: String) -> Bool {
        var st = [Character]()
        
        for c in s {
            if c == "(" || c == "{" || c == "[" {
                st.append(c)
            } else if st.count == 0 {
                return false
            } else if c == ")" {
                if st[st.count - 1] == "(" {
                    st.popLast()
                } else {
                    return false
                }
            } else if c == "}" {
                if st[st.count - 1] == "{" {
                    st.popLast()
                } else {
                    return false
                }
            } else if c == "]" {
                if st[st.count - 1] == "[" {
                    st.popLast()
                } else {
                    return false
                }
            }
        }
        return st.count == 0
    }
}
