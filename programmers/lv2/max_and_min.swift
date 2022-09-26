import Foundation 

func solution(_ s:String) -> String {
    var nums = s.components(separatedBy: " ").map{ Int($0)! }.sorted()
    var ans = ""
    
    ans.append(String(nums[0]))
    ans.append(" ")
    ans.append(String(nums[nums.count - 1]))
    return ans
}
