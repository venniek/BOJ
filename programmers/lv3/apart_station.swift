import Foundation

func solution(_ n:Int, _ stations:[Int], _ w:Int) -> Int{
    var answer = 0
    var start = 1
    let len = w * 2 + 1
    
    func add(_ range: Int) -> Int {
        if range < 0 {
            return 0
        }
        return range / len + (range % len == 0 ? 0 : 1)
    }
    
    for s in stations {
        answer += add(s - w - start)
        start = s + w + 1
    }
    answer += add(n + 1 - start)
    return answer
}
