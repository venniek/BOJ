import Foundation

func solution(_ n:Int, _ build_frame:[[Int]]) -> [[Int]] {
    var wall = [[[Bool]]](repeating: [[Bool]](repeating: [Bool](repeating: false, count: 2), count: n + 4), count: n + 4)
    var ans = [[Int]]()
    
    func check(_ x: Int, _ y: Int, _ a: Int, _ b: Int) -> Bool {
        if a == 0 { // 기둥
            if b == 0 { // 삭제
                if !wall[y + 1][x - 1][1] && !wall[y + 1][x][1] && wall[y + 1][x][0] { return false }
                if !wall[y][x - 1][0] && (!wall[y + 1][x - 2][1] || !wall[y + 1][x][1]) && wall[y + 1][x - 1][1] { return false }
                if !wall[y][x + 1][0] && (!wall[y + 1][x - 1][1] || !wall[y + 1][x + 1][1]) && wall[y + 1][x][1] { return false }
                return true
            } else { // 추가
                if y == 2 || wall[y - 1][x][0] { return true }
                if wall[y][x][1] || wall[y][x - 1][1] { return true }
                return false
            }
        } else { // 보
            if b == 0 { // 삭제
                if !wall[y - 1][x + 1][0] && !wall[y][x + 1][1] && wall[y][x + 1][0] { return false }
                if !wall[y - 1][x][0] && !wall[y][x - 1][1] && wall[y][x][0] { return false }
                if !wall[y - 1][x + 1][0] && !wall[y - 1][x + 2][0] && wall[y][x + 1][1] { return false }
                if !wall[y - 1][x - 1][0] && !wall[y - 1][x][0] && wall[y][x - 1][1] { return false }
                return true
            } else { // 추가
                if wall[y - 1][x][0] || wall[y - 1][x + 1][0] { return true }
                if wall[y][x - 1][1] && wall[y][x + 1][1] { return true }
                return false
            }
        }
    }
    
    // x 가로, y 세로, a 0 기둥 1 보, b 0 삭제 1 추가
    for bf in build_frame {
        let x = bf[0] + 2, y = bf[1] + 2, a = bf[2], b = bf[3]
        if check(x, y, a, b) {
            wall[y][x][a] = (b == 0 ? false : true)
        }
    }
    
    for y in 2...n + 2 {
        for x in 2...n + 2 {
            for i in 0...1 {
                if wall[y][x][i] {
                    ans.append([x - 2, y - 2, i])
                }
            }
        }
    }
    ans.sort(by: {
        return $0[0] < $1[0] || ($0[0] == $1[0] && $0[1] < $1[1]) 
            || ($0[0] == $1[0] && $0[1] == $1[1] && $0[2] < $1[2])
    })
    return ans
}
