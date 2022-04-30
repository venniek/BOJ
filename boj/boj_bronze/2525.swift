import Foundation

let nums = readLine()!.components(separatedBy: " ").map{ Int($0)! }
let time = Int(readLine()!)!
var t = nums[0] * 60 + nums[1] + time
if t < 0 { t += 1440 } else if t > 1439 { t -= 1440 }
print(t / 60, t % 60)
