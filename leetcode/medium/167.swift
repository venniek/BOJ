class Solution {
    func twoSum(_ numbers: [Int], _ target: Int) -> [Int] {
        var ret = [Int](repeating: 0, count: 2)
        var left = 0
        var right = numbers.count - 1
        var sum = numbers[left] + numbers[right]
        while left < right && sum != target {
            if sum > target {
                right -= 1
            } else {
                left += 1
            }
            sum = numbers[left] + numbers[right]
        }
        ret[0] = left + 1
        ret[1] = right + 1
        return ret
    }
}
