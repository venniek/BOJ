class Solution {
    func getHint(_ secret: String, _ guess: String) -> String {
        var m = [Character: Int]()
        let s = Array(secret)
        let g = Array(guess)
        var a = 0
        var b = 0
        
        for i in 0..<s.count {
            if s[i] == g[i] {
                a += 1
            } else {
                if let cnt = m[s[i]] {
                    m[s[i]] = cnt + 1
                } else {
                    m[s[i]] = 1
                }
            }
        }
        for i in 0..<s.count {
            if s[i] != g[i] {
                if let cnt = m[g[i]] {
                    if cnt > 1 {
                        m[g[i]] = cnt - 1
                    } else {
                        m[g[i]] = nil
                    }
                    b += 1
                }
            }
        }
        return String(a) + "A" + String(b) + "B"
    }
}
