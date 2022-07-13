let n = Int(readLine()!)!
var k = 1
var mom: Int
var son: Int

while k * (k + 1) / 2 < n {
	k += 1
}
if k % 2 == 0 {
	mom = k * (k + 1) / 2 - n + 1
	son = k - mom + 1
} else {
	son = k * (k + 1) / 2 - n + 1
	mom = k - son + 1
}
print("\(son)/\(mom)")
