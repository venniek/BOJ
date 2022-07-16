import Foundation

let t = Int(readLine()!)!
for _ in 1...t {
    let nums = readLine()!.components(separatedBy: " ").map{ Int($0)! }
    let floor = nums[2] % nums[0] == 0 ? nums[0] : nums[2] % nums[0]
    let ho = (nums[2] - 1) / nums[0] + 1
    let zero = ho < 10 ? "0" : ""

    print(floor, zero, ho, separator: "")
}
