class Solution {
    func containsDuplicate(_ nums: [Int]) -> Bool {
        var s = Set<Int>()
        for i in nums {
            s.insert(i)
        }
        return nums.count != s.count
    }
}
