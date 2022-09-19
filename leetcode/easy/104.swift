class Solution {
    func maxDepth(_ root: TreeNode?) -> Int {
        if root == nil {
            return 0
        }
        if root!.left == nil && root!.right == nil {
            return 1
        }
        return max(maxDepth(root!.left), maxDepth(root!.right)) + 1
    }
}
