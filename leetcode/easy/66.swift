class Solution {
    func plusOne(_ digits: [Int]) -> [Int] {
        var ans = [Int]()
        let len = digits.count
        
        for i in 1...len {
            let tmp = digits[len - i] + (i == 1 ? 1 : ans[0] / 10)
            ans.insert(tmp, at: 0)
        }
        if ans[0] == 10 {
            ans.insert(1, at: 0)
        }
        ans = ans.map{ $0 % 10 }
        return ans
    }
}
