import Foundation

func solution(_ n:Int, _ costs:[[Int]]) -> Int {
    var bridge = [[(Int, Int)]](repeating: [(Int, Int)](), count: n)
    var done = [Bool](repeating: false, count: n)
    var pool = [(Int, Int)]()
    var ans = 0
    
    for c in costs {
        bridge[c[0]].append((c[1], c[2]))
        bridge[c[1]].append((c[0], c[2]))
    }
    
    for b in bridge[0] {
        pool.append(b)
    }
    
    done[0] = true
    while !pool.isEmpty {
        pool.sort(by: { $0.1 < $1.1 })
        let tmp = pool.removeFirst()
        if done[tmp.0] { continue }
        done[tmp.0] = true
        ans += tmp.1
        for b in bridge[tmp.0] {
            pool.append(b)
        }
    }
    
    return ans
}
