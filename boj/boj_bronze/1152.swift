import Foundation

let str = readLine()!.trimmingCharacters(in: .whitespacesAndNewlines).components(separatedBy: " ")
print(str[0] == "" ? 0 : str.count)

