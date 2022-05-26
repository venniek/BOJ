import Foundation

let nums = readLine()!.components(separatedBy: " ").map{ Int($0)! }
let a = readLine()!.components(separatedBy: " ").map{ Int($0)! }
for i in 0..<nums[0] {
    if a[i] < nums[1] {
        print(a[i], terminator: " ")
    }
}