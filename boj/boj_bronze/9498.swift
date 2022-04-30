import Foundation

let s = Int(readLine()!)!
var g: String

switch s {
    case 90...100: g = "A"
    case 80..<90: g = "B"
    case 70..<80: g = "C"
    case 60..<70: g = "D"
    default: g = "F"
}
print(g)
