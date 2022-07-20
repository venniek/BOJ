class Solution {
    func intersect(_ nums1: [Int], _ nums2: [Int]) -> [Int] {
        var idx1 = 0
        var idx2 = 0
        var ret = [Int]()
        let num1 = nums1.sorted()
        let num2 = nums2.sorted()
        
        while idx1 < num1.count && idx2 < num2.count {
            let diff = num1[idx1] - num2[idx2]
            if diff == 0 {
                ret.append(num1[idx1])
                idx1 += 1
                idx2 += 1
            } else if diff > 0 {
                idx2 += 1
            } else {
                idx1 += 1
            }
        }
        return ret
    }
}
