class Solution {
    func intToRoman(_ num: Int) -> String {
        let m = ["M", "CM", "D", "CD", "C", "XC", "L", 
                 "XL", "X", "IX", "V", "IV", "I"]
        let div = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]
        var ans = ""
        var cn = num
        
        for idx in 0..<div.count {
            let tmp = cn / div[idx]
            for _ in 0..<tmp {
                ans += m[idx]
            }
            cn %= div[idx]
        }
        return ans
    }
}
