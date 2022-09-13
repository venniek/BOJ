class Solution {
    func removeDuplicates(_ nums: inout [Int]) -> Int {
        var a = 0
        
        for i in nums {
            if i != nums[a] {
                a += 1
                nums[a] = i
            }
        }
        return a + 1
    }
}
