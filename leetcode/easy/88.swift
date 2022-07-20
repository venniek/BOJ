class Solution {
    func merge(_ nums1: inout [Int], _ m: Int, _ nums2: [Int], _ n: Int) {
        var idx1 = 0, idx2 = 0, idx = 0
        var tmp = [Int](repeating: 0, count: m + n)
        
        while idx1 < m && idx2 < n {
            if nums1[idx1] <= nums2[idx2] {
                tmp[idx] = nums1[idx1]
                idx1 += 1
            } else {
                tmp[idx] = nums2[idx2]
                idx2 += 1
            }
            idx += 1
        }
        for i in 0..<m - idx1 {
            tmp[idx + i] = nums1[idx1 + i]
        }
        for i in 0..<n - idx2  {
            tmp[idx + i] = nums2[idx2 + i]
        }
        for i in 0..<m+n {
            nums1[i] = tmp[i]
        }
        
    }
}
