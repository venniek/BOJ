import Foundation

let nums = readLine()!.components(separatedBy: " ").map{ Int($0)! }
let a = nums[0]
let b = nums[1]
let c = nums[2]
print((a + b) % c)
print((a + b) % c)
print((a * b) % c)
print((a * b) % c)
