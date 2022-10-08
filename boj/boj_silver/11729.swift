let n = Int(readLine()!)!
var ans = [[Int]]()

func hanoi(_ now: Int, _ from: Int, _ to: Int) {
    if now == 0 {
        return
    }
    hanoi(now - 1, from, 6 - from - to)
    ans.append([from, to])
    hanoi(now - 1, 6 - from - to, to)
}

hanoi(n, 1, 3)
print(1 << n - 1)
for i in ans {
    print(i[0], i[1])
}
