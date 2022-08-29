class Solution {
    func detectCycle(_ head: ListNode?) -> ListNode? {
        var slowNode = head
        var fastNode = head
        while fastNode != nil {
            slowNode = slowNode?.next
            fastNode = fastNode!.next?.next

            if slowNode === fastNode {
                slowNode = head
                while slowNode !== fastNode {
                    slowNode = slowNode?.next
                    fastNode = fastNode?.next
                }
                return slowNode
            }
        }
        return nil
    }
}
