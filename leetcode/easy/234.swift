class Solution {
    func isPalindrome(_ head: ListNode?) -> Bool {
        var str = ""
        var revstr: String
        var h = head
        
        while h != nil {
            str.append(String(h!.val))
            h = h!.next
        }
        revstr = String(str.reversed())
        return str == revstr
    }
}
