import Foundation

let nums = readLine()!.components(separatedBy: " ").map{ Int($0)! }

switch nums[0] - nums[1] {
    case let x where x < 0 : print("<")
    case let x where x == 0 : print("==")
    default : print(">")
}

