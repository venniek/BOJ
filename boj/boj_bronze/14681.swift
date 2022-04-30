import Foundation

let x = Int(readLine()!)!
let y = Int(readLine()!)!
let q: Int

if x * y > 0 {
    if x > 0 { q = 1 } else { q = 3 }
} else {
    if x > 0 { q = 4 } else { q = 2 }
}
print(q)
