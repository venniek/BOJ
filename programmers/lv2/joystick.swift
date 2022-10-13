import Foundation

func solution(_ name:String) -> Int {

    func diff_min(_ lr: [Int], _ sum: Int) {
        var left = lr, right = lr, tmp = 0
        
        if lr.count == 1 {
            diffmin = min(diffmin, sum)
            return 
        }
        tmp = left.removeLast()
        left[0] += tmp
        diff_min(left, sum + tmp)
        tmp = right.removeFirst()
        right[right.count - 1] += tmp
        diff_min(right, sum + tmp)
    }
    
    var lr = [Int]()
    let n = Array(name)
    var ans = 0
    var diffmin = 1000000
    
    for i in 0..<n.count {
        let diff = Int(n[i].asciiValue! - 65)
        ans += min(diff, 26 - diff)
        if i == 0 || diff != 0 {
            lr.append(i)
        }
    }
    for i in 0..<lr.count {
        lr[i] = (i == lr.count - 1 ? n.count : lr[i + 1]) - lr[i]
    }
    diff_min(lr, 0)
    
    return ans + diffmin
}
