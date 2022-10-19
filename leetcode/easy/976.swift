class Solution {
    func largestPerimeter(_ nums: [Int]) -> Int {
        let ns = nums.sorted(by: >)

        for i in 0..<ns.count - 2 {
            if ns[i] < ns[i + 1] + ns[i + 2] {
                return ns[i] + ns[i + 1] + ns[i + 2]
            }
        }
        return 0
    }
}
