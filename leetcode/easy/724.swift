class Solution {
    func pivotIndex(_ nums: [Int]) -> Int {
        var leftSum = 0
        var rightSum = 0
        
        for i in 1..<nums.count {
            rightSum += nums[i]
        }
        if rightSum == 0 {
            return 0
        }
        for i in 1..<nums.count {
            leftSum += nums[i - 1]
            rightSum -= nums[i]
            if rightSum == leftSum {
                return i
            }
        }
        return -1
    }
}
