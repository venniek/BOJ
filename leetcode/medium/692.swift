class Solution {
    func topKFrequent(_ words: [String], _ k: Int) -> [String] {
        var dict = [String: Int]()
        var ans = [String]()
        
        for w in words {
            if let _ = dict[w] {
                dict[w] = dict[w]! + 1
            } else {
                dict[w] = 1
            }
        }
        let sorted = dict.sorted { if $0.1 == $1.1 { return $0.0 < $1.0 }
                                  else { return $0.1 > $1.1 } }
        for i in 0..<k {
            ans.append(sorted[i].key)    
        }
        return ans
    }
}
