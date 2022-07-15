let str = readLine()!.uppercased()
var cnt = [Int](repeating: 0, count: 26)
var maxcnt = -1
var ans:Character =  "-"
var anscnt = 1

for c in str {
	cnt[Int(c.asciiValue! - 65)] += 1
}
for i in 0..<26 {
	if cnt[i] != 0 && cnt[i] > maxcnt {
		maxcnt = cnt[i]
		ans = Character(Unicode.Scalar(65 + i)!)
		anscnt = 1
	} else if cnt[i] == maxcnt {
		anscnt += 1
	}
}
print(anscnt == 1 ? ans : "?")
