import Foundation
let n = Int(readLine()!)!
var sum: Double = 0.0
let nums = readLine()!.components(separatedBy:" ").map{ Double($0)! }
for i in 0..<n {
	sum += nums[i]
}
print(sum / Double(n) / nums.max()! * 100)
