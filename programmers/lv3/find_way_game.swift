import Foundation

struct Point: Hashable {
    let i: Int
    let x: Int
    let y: Int
}

func solution(_ nodeinfo:[[Int]]) -> [[Int]] {
    var nodes = [Point]()
    var dict = [Int: (Int, Int)]()
    var tree = [(Int, Int)]()
    var root = Int()
    var ans = [[Int]](repeating: [Int](), count: 2)
    
    func preor(_ i: Int) {
        ans[0].append(i)
        if tree[i].0 != i { preor(tree[i].0) }
        if tree[i].1 != i { preor(tree[i].1) }
    }
    
    func postor(_ i: Int) {
        if tree[i].0 != i { postor(tree[i].0) }
        if tree[i].1 != i { postor(tree[i].1) }
        ans[1].append(i)
    }

    tree.append((0, 0))
    for idx in 0..<nodeinfo.count {
        let x = nodeinfo[idx][0], y = nodeinfo[idx][1]
        nodes.append(Point(i: idx + 1, x: x, y: y))
        dict[idx + 1] = (x, y)
        tree.append((idx + 1, idx + 1))
    }
    nodes.sort(by: { $0.y > $1.y || ($0.y == $1.y && $0.x < $1.x) })
    root = nodes.removeFirst().i
    while !nodes.isEmpty {
        var now = root
        let node = nodes.removeFirst()
        while true {
            if dict[now]!.0 > node.x {
                if tree[now].0 == now { 
                    tree[now].0 = node.i
                    break
                } else {
                    now = tree[now].0
                }
            } else {
                if tree[now].1 == now {
                    tree[now].1 = node.i
                    break
                } else {
                    now = tree[now].1
                }
            }
        }
    }
    preor(root)
    postor(root)
    return ans
}


