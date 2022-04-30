import Foundation

let a = Int(readLine()!)!
switch a {
    case let x where x < 0 : print("negative")
    case let x where x == 0 : print("zero")
    default : print("positive")
}

