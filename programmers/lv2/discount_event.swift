import Foundation

func allZero(_ need: [String: Int]) -> Bool {
    for n in need {
        if n.value != 0 {
            return false
        }
    }
    return true
}

func solution(_ want:[String], _ number:[Int], _ discount:[String]) -> Int {
    var cnt = 0
    var need = [String: Int]()
    
    for i in 0..<want.count {
        need[want[i]] = number[i]
    }
    for i in 0..<discount.count {
        let now = discount[i]
        
        if let count = need[now] {
            need[now]! -= 1
        }
        if i >= 9 {
            if allZero(need) {
                cnt += 1
            }
            if let _ = need[discount[i - 9]] {
                need[discount[i - 9]]! += 1
            }
        }
    }

    return cnt
}
