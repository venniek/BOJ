import Foundation

func solution(_ n:Int, _ s:Int, _ a:Int, _ b:Int, _ fares:[[Int]]) -> Int {
    var dis = [[Int]](repeating: [Int](repeating: 2147483648, count: n), count: n)
    var ans = 2147483647

    for i in 0..<n {
        dis[i][i] = 0
    }
    
    for i in 0..<fares.count {
        dis[fares[i][0] - 1][fares[i][1] - 1] = fares[i][2]
        dis[fares[i][1] - 1][fares[i][0] - 1] = fares[i][2]
    }
    
    for i in 0..<n {
        for j in 0..<n {
            for k in 0..<n {
                dis[j][k] = min(dis[j][k], dis[j][i] + dis[i][k])
            }
        }
    }

    for i in 0..<n {
        ans = min(ans, dis[s - 1][i] + dis[a - 1][i] + dis[b - 1][i])
    }

    return ans
}
