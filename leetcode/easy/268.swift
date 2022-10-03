class Solution {
    func missingNumber(_ nums: [Int]) -> Int {
        var total = 0
        
        for i in 1...nums.count {
            total += i
            total -= nums[i - 1]
        }
        return total
    }
}
