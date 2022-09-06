class Solution {
    func singleNumber(_ nums: [Int]) -> Int {
        var s = Set<Int>()
        var ans = 0
        
        for n in nums {
            if s.contains(n) {
                s.remove(n)
            } else {
                s.insert(n)
            }
        }
        for n in s {
            ans += n
        }
        return ans
    }
}
