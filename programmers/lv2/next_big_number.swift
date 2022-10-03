import Foundation

func countOne(_ n: Int) -> Int {
    var cn = n
    var ret = 0
    
    while cn > 0 {
        ret += cn & 1
        cn >>= 1
    }
    return ret
}

func solution(_ n:Int) -> Int
{
    var answer = n + 1
    let cnt = countOne(n)
    
    while countOne(answer) != cnt {
        answer += 1
    }
    return answer
}
