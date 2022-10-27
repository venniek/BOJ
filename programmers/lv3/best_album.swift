import Foundation

func solution(_ genres:[String], _ plays:[Int]) -> [Int] {
    var dict = [String: [(Int, Int)]]()
    var ans = [Int]()
    
    for i in 0..<genres.count {
        if let _ = dict[genres[i]] {
            dict[genres[i]]!.append((plays[i], i))
        } else {
            dict[genres[i]] = [(Int, Int)]()
            dict[genres[i]]!.append((plays[i], i))
        }
    }
    for d in dict {
        dict.updateValue(d.value.sorted(by: { ($0.0 > $1.0) || ($0.1 < $1.1) }), forKey: d.key)
    }
    var sortedDict = dict.sorted{ $0.1.reduce(0){ $0 + $1.0 } > $1.1.reduce(0){ $0 + $1.0 } }
    for s in sortedDict {
        for i in 0..<min(2, s.value.count) {
            ans.append(s.value[i].1)
        }
    }
    return ans
}
