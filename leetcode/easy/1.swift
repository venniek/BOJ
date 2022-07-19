class Solution {
    func twoSum(_ nums: [Int], _ target: Int) -> [Int] {
        var ret: [Int] = [0, 0]
        for i in 0..<nums.count - 1 {
            for k in i+1..<nums.count {
                if nums[i] + nums[k] == target {
                    ret[0] = i
                    ret[1] = k
                    break
                }
            }
        }
        return ret
    }
}
