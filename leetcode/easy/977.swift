class Solution {
    func sortedSquares(_ nums: [Int]) -> [Int] {
        var ret = Array(repeating: 0, count: nums.count)
        var left = 0
        var right = 0
        var idx = 0
        for i in 0..<nums.count {
            if nums[i] >= 0 {
                right = i
                break
            }
            if i == nums.count - 1 {
                right = i
            }
        }
        left = right - 1
        if nums[right] == 0  {
            ret[idx] = 0
            right += 1
            idx += 1
        }
        while idx < nums.count {
            if left < 0 {
                ret[idx] = nums[right] * nums[right]
                right += 1
            } else if right >= nums.count {
                ret[idx] = nums[left] * nums[left]
                left -= 1
            } else if nums[left] + nums[right] > 0 {
                ret[idx] = nums[left] * nums[left]
                left -= 1
            } else {
                ret[idx] = nums[right] * nums[right]
                right += 1
            }
            idx += 1
        }
        return ret
    }
}
