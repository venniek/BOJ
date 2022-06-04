import Foundation

let c = Int(readLine()!)!
for _ in 1...c {
	let nums = readLine()!.components(separatedBy: " ").map{ Int($0)! }
	var sum = 0;
	var cnt = 0;
	for i in 1...nums[0] { sum += nums[i] }
	for i in 1...nums[0] {
		if sum < nums[i] * nums[0] { cnt += 1 }
	}
	print(String(format: "%.3f", Double(cnt) / Double(nums[0]) * 100), "%", separator: "")
}

