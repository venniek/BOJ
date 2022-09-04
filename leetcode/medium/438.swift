class Solution {

    func getAlpha(_ s: String) -> [Character : Int] {
        var m = [Character:Int]()
        
        for i in s {
            if let now = m[i] { m[i] = now + 1 } 
            else { m[i] = 1 }
        }
        return m
    }
    
    func findAnagrams(_ s: String, _ p: String) -> [Int] {
        let len = p.count
        var ans = [Int]()
        let news = Array(s)
        let palpha = getAlpha(p)
        var salpha: Dictionary<Character, Int>
        
        if s.count < p.count { return ans }
        salpha = getAlpha(String(s.prefix(len)))
        if salpha == palpha { ans.append(0) }
        for i in len..<news.count {
            if let now = salpha[news[i]] {
                salpha[news[i]] = now + 1
            } else {
                salpha[news[i]] = 1
            }
            if let minus = salpha[news[i - len]] {
                if minus == 1 {
                    salpha[news[i - len]] = nil   
                }
                else {
                    salpha[news[i - len]] = minus - 1
                }
            }
            if salpha == palpha {
                ans.append(i - len + 1)
            }
        }
        return ans
    }
}
