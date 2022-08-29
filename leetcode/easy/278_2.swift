
class Solution : VersionControl {
    func firstBadVersion(_ n: Int) -> Int {
        var start = 1
        var end = n
        
        while start <= end {
            let mid = (start + end) / 2
            if isBadVersion(mid) {
                if mid != 1 && isBadVersion(mid - 1) {
                    end = mid - 1
                } else {
                    return mid
                }
            } else {
                start = mid + 1
            }
        }
        return n
    }
}

