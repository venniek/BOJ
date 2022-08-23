class Solution {
    func isSubsequence(_ s: String, _ t: String) -> Bool {
        let sstr = Array(s)
        var tstr:String = t
        var idx = 0
        
        for i in 0..<s.count {
            if tstr.count == 0 { return false }
            if let index = tstr.index(of: sstr[i]) {
                let pos = tstr.distance(from: tstr.startIndex, to: index)
                tstr = String(tstr.suffix(tstr.count - pos - 1))
            } else {
                return false
            }
        }
        return true
    }
}
