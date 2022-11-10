import Foundation

func solution(_ elements:[Int]) -> Int {
    var sum = Set<Int>()
    let len = elements.count
    
    for start in 0..<len {
        for cnt in 1...len {
            var tmp = 0
            for i in start..<start + cnt {
                tmp += elements[i % len]
            } 
            sum.insert(tmp)
        }
    }

    return sum.count
}
