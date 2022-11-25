import Foundation

func solution(_ board:[[Int]], _ skill:[[Int]]) -> Int {
    let r = board.count, c = board[0].count
    var nujeok = [[Int]](repeating: [Int](repeating: 0, count: c + 1), count: r + 1)
    var ans = 0
    
    for s in skill {
        let ar = s[1], ac = s[2], br = s[3] + 1, bc = s[4] + 1, deg = s[5] * (s[0] == 1 ? -1 : 1)
        nujeok[ar][ac] += deg
        nujeok[br][bc] += deg
        nujeok[ar][bc] -= deg
        nujeok[br][ac] -= deg
    }
    
    for row in 0...r {
        for col in 1...c {
            nujeok[row][col] += nujeok[row][col - 1]
        }
    }
    for row in 1...r {
        for col in 0...c {
            nujeok[row][col] += nujeok[row - 1][col]
        }
    }
    for row in 0..<r {
        for col in 0..<c {
            if board[row][col] + nujeok[row][col] > 0 {
                ans += 1
            }
        }
    }
    
    return ans
}
