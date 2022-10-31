import Foundation

func solution(_ tickets:[[String]]) -> [String] {
    var total = Set<[String]>()
    var visit = [Bool](repeating: false, count: tickets.count)
    
    func dfs(_ from: String, _ strs: [String], _ cnt: Int) {
        if cnt == tickets.count { 
            total.insert(strs)
            return
        }
        for i in 0..<tickets.count {
            if tickets[i][0] == from && !visit[i] {
                visit[i] = true
                var newstrs = strs
                newstrs.append(from)
                if cnt == tickets.count - 1 {
                    newstrs.append(tickets[i][1])
                }
                dfs(tickets[i][1], newstrs, cnt + 1)
                visit[i] = false
            }
        }
    }
    
    dfs("ICN", [String](), 0)
    let sortedTotal = total.sorted(by: {
        for i in 0..<tickets.count + 1 {
            if $0[i] < $1[i] { return true }
            else if $0[i] > $1[i] { return false }
        }
        return false
    })
    return sortedTotal[0]
}
