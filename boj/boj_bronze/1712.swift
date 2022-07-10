import Foundation

let num = readLine()!.components(separatedBy: " ").map{ Double($0)! }
if (num[2] =< num[1]) {
	print(-1)
} else {
	print(Int(floor(num[0] / (num[2] - num[1])) + 1.0));
}