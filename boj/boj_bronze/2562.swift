var ans = 0
var maxn = 0

for i in 1...9 {
	let n = Int(readLine()!)!
	if n > maxn {
		ans = i
		maxn = n
	}
}
print(maxn)
print(ans)
