class Solution {
    func lowestCommonAncestor(_ root: TreeNode?, _ p: TreeNode?, _ q: TreeNode?) -> TreeNode? {
        let s = p!.val < q!.val ? p : q
        let l = p!.val >= q!.val ? p : q
        
        if root!.val >= s!.val && root!.val <= l!.val {
            return root
        } else if root!.val < s!.val{
            return lowestCommonAncestor(root?.right, s, l)
        } else {
            return lowestCommonAncestor(root?.left, s, l)
        }
    }
}
