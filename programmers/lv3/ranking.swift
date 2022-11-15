import Foundation

func solution(_ n:Int, _ results:[[Int]]) -> Int {
    var score = [[Int]](repeating: [Int](repeating: 0, count: n), count: n)

    for r in results {
        let a = r[0] - 1, b = r[1] - 1
        score[a][b] = 1
        score[b][a] = -1
    }
    for i in 0..<n {
        for j in 0..<n {
            for k in 0..<n {
                if score[i][j] == 1 && score[k][i] == 1 { 
                    score[k][j] = 1
                    score[j][k] = -1
                }
            }
        }
    }
    return score.filter{ $0.filter{ $0 == 0 }.count == 1 }.count
}
