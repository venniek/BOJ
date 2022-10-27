import Foundation

func solution(_ number:[Int]) -> Int {
    let len = number.count
    var ans = 0
    
    for i in 0..<len - 2 {
        for j in i + 1..<len - 1 {
            for k in j + 1..<len {
                if number[i] + number[j] + number[k] == 0 {
                    ans += 1
                }
            }
        }
    }
    
    return ans
}
