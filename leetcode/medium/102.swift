class Solution {
    func levelOrder(_ root: TreeNode?) -> [[Int]] {
        var stack = [TreeNode]()
        var tmp = [TreeNode]()
        var ans = [[Int]]()
        
        guard let _ = root else { return [] }
        stack.append(root!)
        while !stack.isEmpty {
            tmp.append(stack[0])
            stack.removeFirst()
            if stack.isEmpty {
                var tmpAns = [Int]()
                for i in tmp {
                    if let l = i.left {
                        stack.append(l)
                    }
                    if let r = i.right{
                        stack.append(r)
                    }
                    tmpAns.append(i.val)
                }
                ans.append(tmpAns)
                tmp.removeAll()
            }   
        }
        return ans
    }
}
