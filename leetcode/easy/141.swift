class Solution {
    func hasCycle(_ head: ListNode?) -> Bool {
        if head != nil {
            if head!.val == 1000000 {
                return true
            } else {
                head!.val = 1000000    
                return hasCycle(head!.next)
            }   
        }
        return false
    }
}
