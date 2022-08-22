class Solution {
    func runningSum(_ nums: [Int]) -> [Int] {
        var ans = [Int](repeating: 0, count: nums.count)
        for i in 0..<nums.count {
            ans[i] = nums[i] + (i == 0 ? 0 : ans[i - 1])
        }
        return ans
    }
}
