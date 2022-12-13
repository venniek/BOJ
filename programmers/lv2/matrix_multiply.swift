import Foundation

func solution(_ arr1:[[Int]], _ arr2:[[Int]]) -> [[Int]] {
    let m = arr1.count
    let n = arr2[0].count
    let len = arr1[0].count
    var ans = [[Int]](repeating: [Int](repeating: 0, count: n), count: m)
    
    for i in 0..<m {
        for j in 0..<n {
            for k in 0..<len {
                ans[i][j] += arr1[i][k] * arr2[k][j]
            }
        }
    }
    
    return ans
}
