import Foundation

func clockwise(_ core: [[Int]]) -> [[Int]] {
    let r = core.count, c = core[0].count
    var ret = [[Int]](repeating: [Int](repeating: 0, count: r), count: c)
    
    for i in 0..<r {
        for j in 0..<c {
            ret[j][r - i - 1] = core[i][j]
        }
    }
    return ret
}

func solution(_ key:[[Int]], _ lock:[[Int]]) -> Bool {
    let m = key.count, n = lock.count
    var l = n - 1, r = 0, u = n - 1, d = 0
    var core = [[Int]]()
    
    func checkKey(_ i: Int, _ j: Int) -> Bool {
        for row in 0..<core.count {
            for col in 0..<core[0].count {
                if i + row >= m || j + col >= m { return false }
                if key[i + row][j + col] + core[row][col] != 1 { return false }
            }
        }
        return true
    }
    
    for i in 0..<n {
        for j in 0..<n {
            if lock[i][j] == 0 {
                l = min(l, j)
                r = max(r, j)
                u = min(u, i)
                d = max(d, i)
            }
        }
    }
    
    if l > r || u > d { return true }
    if r - l + 1 > m || d - u + 1 > m { return false }
    
    for i in u...d {
        core.append(Array(lock[i][l...r]))
    }

    for _ in 0..<4 {
        for i in 0..<m {
            for j in 0..<m {
                if checkKey(i, j) == true { return true }
            }
        }
        core = clockwise(core)
    }

    return false
}
