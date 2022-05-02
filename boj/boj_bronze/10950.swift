import Foundation

let t = Int(readLine()!)!
for _ in 1...t {
	let nums = readLine()!.components(separatedBy: " ").map{ Int($0)! }
	print(nums[0] + nums[1])
}
