import Foundation

let t = Int(readLine()!)!
var arr = [Int]()
for _ in 0..<t {
	let nums = readLine()!.components(separatedBy: " ")
	arr.append(Int(nums[0])! + Int(nums[1])!)
}
for i in 1...t {
	print("Case #\(i): \(arr[i - 1])")
}
