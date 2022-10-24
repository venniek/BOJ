import Foundation

let tmp = readLine()!.components(separatedBy: " ").map{ Int($0)! }
var urls = [String: String]()

for _ in 0..<tmp[0] {
    let strs = readLine()!.components(separatedBy: " ")
    urls[strs[0]] = strs[1]
}
for _ in 0..<tmp[1] {
    let str = readLine()!
    print(urls[str]!)
}
