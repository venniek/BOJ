import Foundation

func solution(_ n:Int, _ edge:[[Int]]) -> Int {
    var edges = [[Int]](repeating: [Int](), count: n)
    var visited = [Bool](repeating: false, count: n)
    var saved = Set<Int>()
    
    for i in 0..<edge.count {
        let tmp = edge[i]
        edges[tmp[0] - 1].append(tmp[1] - 1)
        edges[tmp[1] - 1].append(tmp[0] - 1)
    }
    
    saved.insert(0)
    visited[0] = true
    
    while !saved.isEmpty {
        now = saved.count
        var tmp = Set<Int>()
        for s in saved {
            for es in edges[s] {
                if !visited[es] { 
                    visited[es] = true
                    tmp.insert(es) 
                }
            }
        }
        saved = tmp
    }
    return now
}
