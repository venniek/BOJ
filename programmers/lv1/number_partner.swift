import Foundation

func solution(_ X:String, _ Y:String) -> String {
    var nums = [[Int]](repeating: [Int](repeating: 0, count: 10), count: 2)
    var ans = ""
    let x = Array(X)
    let y = Array(Y)
    
    for i in x {
        nums[0][Int(String(i))!] += 1
    }
    for i in y {
        nums[1][Int(String(i))!] += 1
    }
    for i in 0..<10 {
        let tmp = min(nums[0][10 - i - 1], nums[1][10 - i - 1])
        for k in 0..<tmp {
            ans += String(9 - i)
        }
    }
    return ans.count == min(nums[0][0], nums[1][0]) ? (ans.count == 0 ? "-1" : "0") : ans
}
