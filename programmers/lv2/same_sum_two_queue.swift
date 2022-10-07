import Foundation

func solution(_ queue1:[Int], _ queue2:[Int]) -> Int {
    var q1 = queue1.map{ UInt($0) }
    var q2 = queue2.map{ UInt($0) }
    var sum1: UInt = q1.reduce(0, +)
    var sum2: UInt = q2.reduce(0, +)
    let q = q1 + q2
    var i1 = 0, i2 = queue1.count
    var cnt = 0
    
    if (sum1 + sum2) % 2 == 1 {
        return -1
    }
    while sum1 != sum2 {
        if sum1 > sum2 {
            sum1 -= q[i1]
            sum2 += q[i1]
            i1 += 1
        } else {
            sum1 += q[i2]
            sum2 -= q[i2]
            i2 += 1
        }
        i1 %= q.count
        i2 %= q.count
        cnt += 1
        if cnt > q.count * 2 {
            return -1
        }
    }
    return cnt
}
