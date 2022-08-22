class Solution {
    func climbStairs(_ n: Int) -> Int {
        var stair = [Int](repeating: 0, count: n + 2)
        stair[0] = 0
        stair[1] = 1
        stair[2] = 2
        if n <= 2 {
            return stair[n]
        }
        for i in 3...n {
            stair[i] = stair[i - 1] + stair[i - 2]
        }
        return stair[n]
    }
}
