import Foundation

func solution(_ gems:[String]) -> [Int] {
    var cnt = Set<String>(gems).count
    var start = 0
    var end = cnt - 1
    var ans = [0, 200000]
    var dict = [String: Int]()
    
    for i in start...end {
        let g = gems[i]
        dict[g] = dict[g] == nil ? 1 : dict[g]! + 1
    }
    
    while end < gems.count {
        if dict.count == cnt {
            if ans[1] - ans[0] > end - start {
                ans[0] = start + 1
                ans[1] = end + 1
            }
            dict[gems[start]] = dict[gems[start]]! == 1 ? nil : dict[gems[start]]! - 1
            start += 1
        } else {
            if end == gems.count - 1 { break }
            end += 1
            dict[gems[end]] = dict[gems[end]] == nil ? 1 : dict[gems[end]]! + 1
        }
    }
    
    return ans
}
