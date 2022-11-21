import Foundation

let n = Int(readLine()!)!
var nums = readLine()!.components(separatedBy: " ").map{ Int($0)! }
let m = Int(readLine()!)!

for i in 0..<nums.count {
    if i == 0 { continue }
    else { nums[i] += nums[i - 1] }
}
for _ in 0..<m {
    let r = readLine()!.components(separatedBy: " ").map{ Int($0)! }
    print(nums[r[1] - 1] - (r[0] == 1 ? 0 : nums[r[0] - 2]))
}
