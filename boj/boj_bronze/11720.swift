let n = Int(readLine()!)!
let str = readLine()!
var ans: Int = 0

for c in str {
    ans += c.wholeNumberValue!
}

print(ans)
