var n: Int = 1
var cnt = [Int](repeating: 0, count: 10)

for _ in 1...3 {
	n *= Int(readLine()!)!
}
while n > 0 {
	cnt[n % 10] += 1
	n /= 10
}
for c in cnt {
	print(c)
}
