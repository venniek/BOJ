/**
 * The knows API is defined in the parent class VersionControl.
 *     func isBadVersion(_ version: Int) -> Bool{}
 */

class Solution : VersionControl {
    func firstBadVersion(_ n: Int) -> Int {
        var start = 0
        var end = n
        while start <= end {
            let mid = (start + end) / 2
            if !isBadVersion(mid) {
                start = mid + 1
            } else {
                end = mid - 1
            }
        }
        return start
    }
}
