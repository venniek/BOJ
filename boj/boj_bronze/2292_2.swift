import Foundation

let n = Int(readLine()!)!
let ans = ceil((sqrt(Double(12 * n - 3)) - 3) / 6)
print(Int(ans) + 1)
