class Solution {
    func maxSubArray(_ nums: [Int]) -> Int {
        var sum = -100000
        var max_sum = -100000
        for i in nums {
            sum = max(sum + i, i)
            max_sum = max(max_sum, sum)
        }
        return max_sum
    }
}
