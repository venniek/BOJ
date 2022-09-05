class Solution {
    func lastStoneWeight(_ stones: [Int]) -> Int {
        var pq = stones.sorted { return $0 > $1 }

        while pq.count > 1 {
            let first = pq[0]; pq.removeFirst()
            let second = pq[0]; pq.removeFirst()
            
            if first != second {
                pq.append(first - second)
            }
            pq.sort { return $0 > $1 }
        }
        return pq.count == 1 ? pq[0] : 0
    }
}
