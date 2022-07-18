class Solution {
    func moveZeroes(_ nums: inout [Int]) {
        var idx = 0
        var now = 0
        while idx < nums.count {
            if nums[idx] != 0 {
                nums[now] = nums[idx]
                now += 1
            }
            idx += 1
        }
        while now < nums.count {
            nums[now] = 0
            now += 1
        }
    }
}
