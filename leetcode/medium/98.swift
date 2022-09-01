class Solution {
    func midOrder(_ root: TreeNode?) -> [Int] {
        var ret = [Int]()
        
        if let l = root?.left {
            ret += midOrder(l)
        }
        ret.append(root!.val)
        if let r = root?.right {
            ret += midOrder(r)
        }
        return ret
    }
    
    func isValidBST(_ root: TreeNode?) -> Bool {
        let nums: [Int] = midOrder(root)
        
        for i in 0..<nums.count - 1 {
            if nums[i] >= nums[i + 1] {
                return false
            }
        }
        return true
    }
}
