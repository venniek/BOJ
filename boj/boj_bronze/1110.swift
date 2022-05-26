var n = Int(readLine()!)!
let nc = n
var cnt: Int = 0;

repeat {
    let a = n / 10
    let b = n % 10
    n = b * 10 + (a + b) % 10
    cnt += 1
} while n != nc
print(cnt)