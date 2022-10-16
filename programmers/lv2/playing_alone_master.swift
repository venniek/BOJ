import Foundation

func solution(_ cards:[Int]) -> Int {
    var maxs = [Int]()
    var done = cards
    var now = 0
    
    func group(_ i: Int) {
        now += 1
        let tmp = done[i] - 1
        done[i] = 0
        if done[tmp] == 0 {
            return
        }
        group(tmp)
    }
    
    for i in 0..<done.count {
        if done[i] != 0 {
            group(i)
            maxs.append(now)
            now = 0
        }
    }
    if maxs.count == 1 {
        return 0
    }
    maxs.sort(by: >)
    return maxs[0] * maxs[1]
}
