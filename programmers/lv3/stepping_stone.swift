import Foundation

func solution(_ stones:[Int], _ k:Int) -> Int {
    var left = 1
    var right = stones.max()!
    
    func check(_ mid: Int) -> Bool {
        var cnt = 0
        
        for i in 0..<stones.count {
            if stones[i] < mid { cnt += 1 } else { cnt = 0 }
            if cnt >= k { return false }
        }
        return true
    }
    
    while left <= right {
        let mid = (right + left) / 2
        if check(mid) {
            left = mid + 1
        } else {
            right = mid - 1
        }
    }   
    return right
}
