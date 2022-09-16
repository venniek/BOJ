class Solution {
    func inorderTraversal(_ root: TreeNode?) -> [Int] {
        var tmp = [Int]()
        
        if root == nil {
            return []
        }
        tmp.append(contentsOf: inorderTraversal(root!.left))
        tmp.append(root!.val)
        tmp.append(contentsOf: inorderTraversal(root!.right))
        return tmp
    }
}
