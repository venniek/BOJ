import Foundation

let c = Int(readLine()!)!
for _ in 1...c {
	let nums = readLine()!.components(separatedBy: " ").map{ Int($0)! }
	var sum = 0;
	var cnt = 0;
	for i in 1...nums[0] {
		sum += nums[i]
	}
	for i in 1...nums[0] {
		if (Double(sum) / Double(nums[0])) < Double(nums[i]) { cnt += 1 }
	}
	print(String(format: "%.3f", Double(cnt) / Double(nums[0]) * 100), "%", separator: "")
}

// 처음부터 Double로 받지 말고 Int로 계산한 후에 나눌 때만 변환해주기
