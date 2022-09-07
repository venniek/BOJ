import Foundation

let total = Int(readLine()!)!
let n = Int(readLine()!)!
var sum = 0

for _ in 0..<n {
    let tmp = readLine()!.components(separatedBy: " ").map{ Int($0)! }
    sum += tmp[0] * tmp[1]
}

print(sum == total ? "Yes" : "No")
