class Solution {
    func rotate(_ nums: inout [Int], _ k: Int) {
        var ret = Array(repeating: 0, count: nums.count)
        var idx = 0
        while idx < nums.count {
            ret[(idx + k) % nums.count] = nums[idx]
            idx += 1
        }
        idx = 0
        while idx < nums.count {
            nums[idx] = ret[idx]
            idx += 1
        }
    }
}
