class Solution {
    func mySqrt(_ x: Int) -> Int {
        var left = 0
        var right = x
        
        while left < right {
            let mid = (left + right) / 2
            let tmp = mid * mid
            if tmp == x {
                return mid
            } else if tmp > x {
                right = mid - 1
            } else {
                left = mid + 1
            }
        }
        return left * left <= x ? left : left - 1
    }
}
