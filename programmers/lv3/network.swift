import Foundation

func solution(_ n:Int, _ computers:[[Int]]) -> Int {
    var used = [Bool](repeating: false, count: n)
    var com = computers
    var ans = 0
    
    if n == 1 {
        return 1
    }
    
    func link(_ idx: Int) {
        used[idx] = true
        for i in 0..<com.count {
            if com[idx][i] == 1 {
                com[idx][i] = 0
                link(i)
            }
        }
    }
    
    for i in 0..<com.count {
        for j in 0..<com[i].count {
            if i == j { continue }
            if com[i][j] == 1 {
                link(i)
                ans += 1
                continue
            }
        }
    }
    
    return ans + used.filter{ $0 == false }.count
}
