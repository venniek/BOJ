class Solution {
    func sortedArrayToBST(_ nums: [Int]) -> TreeNode? {
        if nums.count == 0 {
            return nil
        }
        let mididx = nums.count / 2
        var ret: TreeNode? = TreeNode(nums[mididx])
        
        ret!.left = sortedArrayToBST(Array(nums[0..<mididx]))
        ret!.right = sortedArrayToBST(Array(nums[mididx + 1..<nums.count]))
        
        return ret
    }
}
