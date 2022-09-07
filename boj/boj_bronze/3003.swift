import Foundation

let have = readLine()!.components(separatedBy: " ").map{ Int($0)! }
var all = [1, 1, 2, 2, 2, 8]

for i in 0..<6 {
    print(all[i] - have[i], terminator: " ")
}
