class Solution {
    func checkIfPangram(_ sentence: String) -> Bool {
        var alpha = Set<Character>()
        for s in sentence {
            alpha.insert(s)
            if alpha.count == 26 {
                return true
            }
        }
        return alpha.count == 26
    }
}
