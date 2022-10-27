import Foundation

let n = Int(readLine()!)!
var dp = [Int](repeating: 0, count: n + 1)

for i in 1...n {
    if i == 1 { dp[i] = 1 }
    else if i == 2 { dp[i] = 2 }
    else { dp[i] = (dp[i - 1] + dp[i - 2]) % 10007}
}

print(dp[n])
