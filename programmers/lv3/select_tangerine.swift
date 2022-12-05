import Foundation

func solution(_ k:Int, _ tangerine:[Int]) -> Int {
    var dict = [Int: Int]()
    var sorted = [Int]()
    var k = tangerine.count - k
    
    for t in tangerine {
        if let _ = dict[t] {
            dict[t]! += 1
        } else {
            dict[t] = 1
        }
    }
    for d in dict {
        sorted.append(d.value)
    }
    sorted.sort{ $0 < $1 }
    while k > 0 {
        sorted[0] -= 1
        k -= 1
        if sorted[0] == 0 { sorted.removeFirst() }
    }
    
    return sorted.count
}
