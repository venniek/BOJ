let n = Int(readLine()!)!

for _ in 1...n {
	var now = 0
	var sum = 0
	for c in readLine()! {
		if c == "O" {
			now += 1
			sum += now
		} else {
			now = 0
		}
	}
	print(sum)
}
