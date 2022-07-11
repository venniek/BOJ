import Foundation

for _ in 1...Int(readLine()!)! {
	let test = readLine()!.components(separatedBy: " ")
	for c in test[1] {
		for _ in 1...Int(test[0])! {
			print(c, terminator: "")
		}
	}
	print("")
}
