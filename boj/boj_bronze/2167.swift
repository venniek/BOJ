import Foundation

let nm = readLine()!.components(separatedBy: " ").map{ Int($0)! }
var board = [[Int]](repeating: [Int](repeating: 0, count: nm[1] + 1), count: nm[0] + 1)

for i in 0...nm[0] { board[i][0] = 0 }
for j in 0...nm[1] { board[0][j] = 0 }

for i in 1...nm[0] {
    let tmp = readLine()!.components(separatedBy: " ").map{ Int($0)! }
    for j in 1...nm[1] {
       board[i][j] = board[i - 1][j] + board[i][j - 1] - board[i - 1][j - 1] + tmp[j - 1] 
    }
}

let k = Int(readLine()!)!
for _ in 0..<k {
    let tmp = readLine()!.components(separatedBy: " ").map{ Int($0)! }
    let i = tmp[0], j = tmp[1], x = tmp[2], y = tmp[3]
    print(board[x][y] - board[i - 1][y] - board[x][j - 1] + board[i - 1][j - 1])
}
