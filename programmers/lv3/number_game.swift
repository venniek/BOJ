import Foundation

func solution(_ a:[Int], _ b:[Int]) -> Int {
    let asort = a.sorted()
    let bsort = b.sorted()
    var ai = 0, bi = 0
    
    while bi < bsort.count {
        if asort[ai] < bsort[bi] {
            ai += 1
        }
        bi += 1
    }
    
    return ai
}
