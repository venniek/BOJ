import Foundation

func solution(_ board:[[Int]]) -> Int {
    let len = board.count
    // [x][y][dir]  dir: 0 - 위아래 x , 1 - 왼쪽오른쪽 y
    var price = [[[Int]]](repeating: [[Int]](repeating: 
                                             [Int](repeating: 1000000, count: 2), count: len), count: len)
    var pool = [(Int, Int, Int)]() // (x, y, dir)
    let dx = [1, 0, -1, 0]
    let dy = [0, 1, 0, -1]
    
    pool.append((0, 0, -1))
    price[0][0][0] = 0
    price[0][0][1] = 0
    
    while !pool.isEmpty {
        var tmp = [(Int, Int, Int)]()
        while !pool.isEmpty {
            let first = pool.removeFirst()
            for i in 0..<4 {
                let nx = first.0 + dx[i]
                let ny = first.1 + dy[i]
                if nx < 0 || ny < 0 || nx == len || ny == len || board[nx][ny] == 1 { continue }
                let next = price[first.0][first.1][max(0, first.2) % 2] 
                            + (first.2 == -1 || abs(first.2 - i) % 2 == 0 ? 1 : 6)
                if next < price[nx][ny][i % 2] {
                    price[nx][ny][i % 2] = next
                    tmp.append((nx, ny, i))
                }
            }
        }
        pool = tmp
    }
    
    return price[len - 1][len - 1].min()! * 100
}
