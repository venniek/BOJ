class Solution {
    func middleNode(_ head: ListNode?) -> ListNode? {
        var tmpNode = head
        var cnt = 0
        while tmpNode != nil {
            tmpNode = tmpNode?.next
            cnt += 1
        }
        var ans = cnt / 2
        tmpNode = head
        while ans > 0 {
            tmpNode = tmpNode?.next
            ans -= 1
        }
        return tmpNode
    }
}
