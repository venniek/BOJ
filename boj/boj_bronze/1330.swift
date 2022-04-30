import Foundation

let nums = readLine()!.components(separatedBy: " ").map{ Int($0)! }
let a = nums[0] - nums[1]

if a > 0 {
    print(">")
} else if a < 0 {
    print("<")
} else {
    print("==")
}
