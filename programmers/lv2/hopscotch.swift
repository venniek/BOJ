import Foundation

func solution(_ land:[[Int]]) -> Int{
    func getMax(_ row: [Int], _ i: Int) -> Int {
        var ret = 0
        for idx in 0..<4 {
            if idx != i {
                ret = max(ret, row[idx])
            }
        }
        return ret
    }
    
    var answer = 0
    var cl: [[Int]] = land
    
    for r in 1..<cl.count {
        for i in 0..<4 {
            cl[r][i] += getMax(cl[r - 1], i)
        }
    }
    return cl[cl.count - 1].max()!
}
