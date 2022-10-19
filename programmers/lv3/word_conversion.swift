import Foundation

func solution(_ begin:String, _ target:String, _ words:[String]) -> Int {
    var minans = 100
    var used = [Bool](repeating: false, count: words.count + 1)
    var words = words
    
    func oneDiff(_ s1: [Character], _ s2: [Character]) -> Bool {
        var cnt = 0
        for i in 0..<s1.count {
            if s1[i] != s2[i] {
                if cnt == 1 {
                    return false
                }
                cnt = 1
            }
        }
        return cnt == 1
    }
    
    func findAns(_ idx: Int, _ cnt: Int) {
        if words[idx] == target {
            minans = min(minans, cnt)
            return
        }
        if cnt > words.count {
            return
        }
        for i in 1..<words.count {
            if !used[i] && oneDiff(Array(words[i]), Array(words[idx])) {
                used[i] = true
                findAns(i, cnt + 1)
                used[i] = false
            }
        }
    }
        
    if !words.contains(target) {
        return 0
    }

    words.insert(begin, at: 0)
    used[0] = true
    findAns(0, 0)

    return minans
}
