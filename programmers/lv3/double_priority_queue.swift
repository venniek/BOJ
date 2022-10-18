import Foundation

func solution(_ operations:[String]) -> [Int] {
    var nums = [Int]()
    
    for o in operations {
        let tmp = o.components(separatedBy: " ")
        if tmp[0] == "I" {
            nums.append(Int(tmp[1])!)
            nums.sort()
        } else {
            if tmp[1] == "1" {
                if !nums.isEmpty {
                nums.removeLast()    
                }
                
            } else {
                if !nums.isEmpty {
                nums.removeFirst()    
                }
            }
        }
    }
    if nums.isEmpty {
        return [0, 0]
    }
    return [nums[nums.count - 1], nums[0]] 
}
