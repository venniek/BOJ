import Foundation

while let input = readLine() {
    let ns = input.components(separatedBy: " ").map{ Int($0)! }
    print(ns[0] + ns[1])
}