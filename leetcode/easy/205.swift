class Solution {
    func isIsomorphic(_ s: String, _ t: String) -> Bool {
        let sstr = Array(s)
        let tstr = Array(t)
        var m = [Character: Character]()
        
        for i in 0..<sstr.count {
            if !m.keys.contains(sstr[i]) {
                if !m.values.contains(tstr[i]) {
                    m[sstr[i]] = tstr[i]
                } else { return false }
            } else if m[sstr[i]] != tstr[i] {
                return false
            }
        }
        return true
    }
}
