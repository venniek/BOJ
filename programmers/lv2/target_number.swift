import Foundation

func solution(_ numbers:[Int], _ target:Int) -> Int {
    var ans = 0
    
    func nextNumber(_ idx: Int, _ now: Int) {
        if idx == numbers.count {
            if now == target {
                ans += 1
            }
            return
        }
        nextNumber(idx + 1, now + numbers[idx])
        nextNumber(idx + 1, now - numbers[idx])
    }    
    nextNumber(0, 0)

    return ans
}
