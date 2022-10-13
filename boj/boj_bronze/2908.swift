import Foundation

print(readLine()!.components(separatedBy: " ").map{ Int(String($0.reversed()))! }.max()!)
