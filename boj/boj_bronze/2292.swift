let n = Int(readLine()!)!
var idx = 0
while true {
	if n <= idx * (idx + 1) * 3 + 1 {
		print(idx + 1)
		break
	}
	idx += 1
}