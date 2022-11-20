import Foundation

func solution(_ n:Int, _ k:Int, _ cmd:[String]) -> String {
    var list = [(Int, Int)]()
    var deleted = [Int]()
    var select = k
    var ans = ""
    
    for i in 0..<n {
        list.append((i - 1, i + 1))
    }
    for c in cmd {
        if c.count == 1 {
            if c == "C" {
                deleted.append(select)
                let now = list[select]
                if now.0 != -1 {
                    list[now.0].1 = now.1
                }
                if now.1 == n {
                    select = now.0
                } else {
                    select = now.1
                    list[now.1].0 = now.0
                }
            } else {
                let back = deleted.removeLast()
                if list[back].0 != -1 {
                    list[list[back].0].1 = back
                }
                if list[back].1 != n {
                    list[list[back].1].0 = back
                }
            }
        } else {
            let split = c.components(separatedBy: " ")
            var cnt = Int(split[1])!
            if split[0] == "U" {
                while cnt > 0 {
                    select = list[select].0
                    cnt -= 1
                }
            } else {
                while cnt > 0 {
                    select = list[select].1
                    cnt -= 1
                }
            }
        }
    }
    deleted.sort()
    for i in 0..<n {
        if !deleted.isEmpty && i == deleted[0] {
            ans += "X"
            deleted.removeFirst()
        } else {
            ans += "O"
        }
    }
    
    return ans
}

