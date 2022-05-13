import Foundation

let t = Int(readLine()!)!
for cnt in 0..<t {
	let nums = readLine()!.components(separatedBy: " ").map{ Int($0)! }
	print("Case #\(cnt + 1): \(nums[0]) + \(nums[1]) = \(nums[0] + nums[1])")
}
