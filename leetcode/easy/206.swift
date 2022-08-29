class Solution {
    func reverseList(_ head: ListNode?) -> ListNode? {
        if head?.next == nil {
            return head
        }
        let p = reverseList(head?.next)
        head?.next?.next = head
        head?.next = nil
        
        return p
    }
}
