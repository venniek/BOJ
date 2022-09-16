class Solution {
    func orderTraversal(_ root: TreeNode?, _ flag: Int) -> [Int] {
        var tmp = [Int]()
        
        if root == nil {
            return [-200]
        }
        if root!.left == nil && root!.right == nil {
            return [root!.val]
        }
        if flag == 1 {
            tmp.append(contentsOf: orderTraversal(root!.left, flag))
            tmp.append(contentsOf: orderTraversal(root!.right, flag))
        } else {
            tmp.append(contentsOf: orderTraversal(root!.right, flag))
            tmp.append(contentsOf: orderTraversal(root!.left, flag))
        }
        tmp.append(root!.val)
        return tmp
    }
    
    func isSymmetric(_ root: TreeNode?) -> Bool {
        let a = orderTraversal(root!.left, 1)
        let b = orderTraversal(root!.right, 0)
        return a == b
    }
}
