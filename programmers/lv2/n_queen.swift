import Foundation

func solution(_ n:Int) -> Int {
    var board = [Int](repeating: 0, count: n)
    var cnt = 0
    
    func is_ok(_ i: Int, _ now: Int) -> Bool {
        for j in 0..<now {
            if board[j] == i || abs(now - j) == abs(i - board[j]) {
                return false
            }
        }
        return true
    }
    
    func add_one(_ i: Int, _ now: Int) {
        if is_ok(i, now) {
            board[now] = i
            if now == n - 1 {
                cnt += 1
            } else {
                for j in 0..<n {
                    add_one(j, now + 1)
                }    
            }
            board[now] = 0   
        }
    }
    
    for i in 0..<n {
        add_one(i, 0)
    }
    
    return cnt
}
