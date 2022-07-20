class Solution {
    func maxProfit(_ prices: [Int]) -> Int {
        let len = prices.count
        var arr: [[Int]] = Array(repeating: Array(repeating: 0, count: len), count: 2)
		var ans = 0
		arr[0][0] = prices[0]
		arr[1][len - 1] = prices[len - 1]
		for i in 1..<len {
            arr[0][i] = min(prices[i], arr[0][i - 1])
            arr[1][len - i - 1] = max(prices[len - i - 1], arr[1][len - i])
        }
        for i in 0..<len {
            ans = max(ans, arr[1][i] - arr[0][i])
        }
        return ans
    }
}
