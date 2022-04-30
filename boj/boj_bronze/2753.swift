import Foundation

let a = Int(readLine()!)!
if (a % 4 == 0 && a % 100 != 0) || a % 400 == 0 {
    print(1)
} else {
    print(0)
}
