import Foundation

func solution(_ n:Int, _ times:[Int]) -> Int64 {
    var left: Int64 = 1
    var right: Int64 = 1000000000000000000
    
    func timeSum(_ mid: Int64) -> Bool {
        var ret: Int64 = 0
        
        for i in 0..<times.count {
            ret += mid / Int64(times[i])
            if ret >= n { return false }
        }
        return true
    }
    
    while left <= right {
        let mid = (left + right) / 2
        if timeSum(mid) {
            left = mid + 1
        } else {
            right = mid - 1
        }
    }
    return left
}
