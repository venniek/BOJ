class Solution {
    func removeNthFromEnd(_ head: ListNode?, _ n: Int) -> ListNode? {
        var tmpNode = head
        var cnt = 0
        while tmpNode != nil {
            tmpNode = tmpNode?.next
            cnt += 1
        }
        tmpNode = head
        var prevNode: ListNode? = nil
        var ans = cnt - n
        while ans > 0 {
            prevNode = tmpNode
            tmpNode = tmpNode?.next
            ans -= 1
        }
        if prevNode == nil {
            return head?.next
        } else {
            prevNode?.next = tmpNode?.next   
        }
        return head
    }
}

