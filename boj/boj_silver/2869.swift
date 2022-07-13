import Foundation

let abv = readLine()!.components(separatedBy: " ").map{ Int($0)! }
let diff = abv[0] - abv[1]
let tree = abv[2] - abv[0]
let ans = tree / diff + (tree % diff != 0 ? 1 : 0) + 1

print(ans)
