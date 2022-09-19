class Solution {
    func merge(_ nums1: inout [Int], _ m: Int, _ nums2: [Int], _ n: Int) {
        var i1 = m - 1, i2 = n - 1, idx = m + n - 1
        
        while i1 >= 0 && i2 >= 0 {
            if nums1[i1] > nums2[i2] {
                nums1[idx] = nums1[i1]
                i1 -= 1
            } else {
                nums1[idx] = nums2[i2]
                i2 -= 1
            }
            idx -= 1
        }
        if i2 >= 0 {
            for i in 0...i2 {
                nums1[i] = nums2[i]
            }
        }
    }
}
