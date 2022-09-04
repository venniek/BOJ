class Solution {
    func twoSum(_ nums: [Int], _ target: Int) -> [Int] {
        var m = [Int: Int]()
        
        for i in 0..<nums.count  {
            let now = nums[i]
            let need = target - now
            if m.isEmpty {
                m[now] = i
            } else {
                if let idx = m[need] {
                    return [idx, i]
                } else {
                    m[now] = i
                }
            }
        }
        return [0, 1]
    }
}

