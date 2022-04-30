import Foundation

let nums = readLine()!.components(separatedBy: " ").map{ Int($0)! }
let a = nums[0]
let b = nums[1]
print(a + b)
print(a - b)
print(a * b)
print(a / b)
print(a % b)
