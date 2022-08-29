class Solution {
    func preorder(_ root: Node?) -> [Int] {
        var ret = [Int]()
        
        if root == nil {
            return []
        }
        ret.append(root!.val)
        for child in root!.children {
            let tmp = preorder(child)
            for num in tmp {
                ret.append(num)
            }
        }
        return ret
    }
}
