import Foundation

let title = readLine()!.components(separatedBy: " ").map{ Int($0)! }
let point = title[0], edge = title[1]
var map = [[Int]](repeating: [Int](), count: point)
var visit = [Bool](repeating: false, count: point)
var ans = 0

for _ in 0..<edge {
    let tmp = readLine()!.components(separatedBy: " ").map{ Int($0)! }
    map[tmp[0] - 1].append(tmp[1] - 1)
    map[tmp[1] - 1].append(tmp[0] - 1)
}

func link(_ idx: Int) {
    for i in map[idx] {
        if !visit[i] {
            visit[i] = true
            link(i)
        }
    }
}

for i in 0..<map.count {
    if !visit[i] {
        visit[i] = true
        link(i)
        ans += 1
    }
}
print(ans)

