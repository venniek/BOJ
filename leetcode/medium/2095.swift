class Solution {
    func deleteMiddle(_ head: ListNode?) -> ListNode? {
        var fast: ListNode? = head
        var slow: ListNode? = head
        var prev: ListNode?
        
        if slow == nil || slow!.next == nil {
            return nil
        }
        while fast != nil && fast!.next != nil {
            prev = slow
            fast = fast!.next!.next
            slow = slow!.next
        }
        prev!.next = prev!.next!.next
        return head
    }
}
