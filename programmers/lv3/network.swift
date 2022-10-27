import Foundation

func solution(_ n:Int, _ computers:[[Int]]) -> Int {
    var com = computers
    var ans = 0
    var flag: Bool
    
    func link(_ idx: Int) {
        for i in 0..<com.count {
            if i != idx && com[idx][i] == 1 {
                flag = true
                com[i][i] = 0
                com[idx][i] = 0
                link(i)
            }
        }
    }
    
    for i in 0..<com.count {
        flag = false
        link(i)
        if flag || com[i][i] == 1 {
            ans += 1
        }
    }
    
    return ans
}
