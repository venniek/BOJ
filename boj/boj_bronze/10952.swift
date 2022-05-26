import Foundation

while true {
    let nums = readLine()!.components(separatedBy: " ").map{ Int($0)! }
    if nums[0] + nums[1] == 0 { break }
    print(nums[0] + nums[1])
}