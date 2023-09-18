import Foundation

let n = Int(readLine()!)!
let minus: Int = Int(round(Double(n) * 0.15))
var ops = [Double]()
var sum: Double = 0

for _ in 0..<n {
    let d = Double(readLine()!)!
    ops.append(d)
}
ops.sort()
if minus != 0 {
    for i in minus..<n - minus {
        sum += ops[i]
    }
}
print(Int(round(sum / Double(n - minus * 2))))
