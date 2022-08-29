class Solution {
    func longestPalindrome(_ s: String) -> Int {
        guard !s.isEmpty else { return 0 }
        var res = 0, set = Set<Character>()
        for ch in s {
            if set.contains(ch) {
                res += 2
                set.remove(ch)
            } else {
                set.insert(ch)
            }
        }
        return !set.isEmpty ? res + 1 : res
    }
}
