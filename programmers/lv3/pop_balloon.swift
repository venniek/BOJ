import Foundation

func solution(_ a:[Int]) -> Int {
    var avail = [Int]()
    var i = 0
    
    func checkAvail(_ num: Int) -> Bool {
        let len = avail.count
        
        if avail[len - 1] > avail[len - 2] && avail[len - 1] > num {
            return false
        }
        return true
    }
    
    while i < a.count {
        if avail.count < 2 || checkAvail(a[i]) {
            avail.append(a[i])
            i += 1
        } else {
            avail.removeLast()
        }
    }
    return avail.count
}
