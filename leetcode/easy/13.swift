class Solution {
    func romanToInt(_ s: String) -> Int {
        let m: [Character: Int] = ["I": 1, "V": 5, "X": 10, "L": 50, "C": 100, "D": 500, "M": 1000]
        var prev = 0
        var ans = 0
        let str = Array(s)
        
        for i in 1...str.count {
            let now = m[str[str.count - i]]!
            ans += now >= prev ? now : -now
            prev = now
        }
        return ans
    }
}
