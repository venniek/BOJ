import Foundation

func solution(_ n:Int, _ s:Int, _ a:Int, _ b:Int, _ fares:[[Int]]) -> Int {
    var road = [[(Int, Int)]](repeating: [(Int, Int)](), count: n + 1)
    var fromS: [Int]
    var fromA: [Int]
    var fromB: [Int]
    var ans = 2147483647
    
    // 다익스트라로 start에서 모든 정점까지 최소 요금 구하기
    func findShortest(_ start: Int) -> [Int] {
        var dis = [Int](repeating: 2147483647, count: n + 1)
        var pool = [(Int, Int)]()
        
        dis[start] = 0
        pool.append((start, 0))
        
        while !pool.isEmpty {
            pool.sort(by: { $0.1 < $1.1 } )
            let now = pool.removeFirst()
            if dis[now.0] != now.1 { continue }
            let nexts = road[now.0]
            for i in 0..<nexts.count {
                if now.1 + nexts[i].1 < dis[nexts[i].0] {
                    dis[nexts[i].0] = now.1 + nexts[i].1
                    pool.append((nexts[i].0, now.1 + nexts[i].1))
                }
            }
        }
        return dis
    }
    
    // 각 정점별로 (목적지, 요금) 배열 만들기
    for i in 0..<fares.count {
        road[fares[i][0]].append((fares[i][1], fares[i][2]))
        road[fares[i][1]].append((fares[i][0], fares[i][2]))
    }
    
    // s, a, b에서 각각 모든 정점까지 최소 요금 구하기
    fromS = findShortest(s)
    fromA = findShortest(a)
    fromB = findShortest(b)

    // s->0 + 0->a + 0->b 최종 요금 min 값 구하기
    for i in 1...n {
        ans = min(ans, fromS[i] + fromA[i] + fromB[i])
    }

    return ans
}
