import Foundation

let num = readLine()!.components(separatedBy: " ").map{ Int($0)! }
var numToName = [Int: String]()
var nameToNum = [String: Int]()

for i in 1...num[0] {
    let name = readLine()!
    numToName[i] = name
    nameToNum[name] = i
}
for _ in 0..<num[1] {
    let tmp = readLine()!
    if let n = nameToNum[tmp] {
        print(n)
    } else {
        print(numToName[Int(tmp)!]!)
    }
}
