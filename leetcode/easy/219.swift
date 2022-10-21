class Solution {
    func containsNearbyDuplicate(_ nums: [Int], _ k: Int) -> Bool {
        var s = Set<Int>()
        let nk = min(nums.count - 1, k)
        
        for i in 0..<nums.count {
            s.insert(nums[i])
            if i >= nk && s.count < nk + 1 {
                return true
            }
            if s.count == nk + 1 {
                s.remove(nums[i - nk])
            }
        }
        return false
    }
}
