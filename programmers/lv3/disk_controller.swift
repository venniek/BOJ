import Foundation

func solution(_ jobs:[[Int]]) -> Int {
    var job = jobs.sorted(by: { $0[0] < $1[0] })
    var pool = [[Int]]()
    var ans = 0
    var time = 0
    
    while !job.isEmpty || !pool.isEmpty {
        while !job.isEmpty && job[0][0] <= time {
            pool.append(job.removeFirst())
            pool.sort(by: { $0[1] < $1[1] })
        }
        if !pool.isEmpty {
            let tmp = pool.removeFirst()
            ans += time - tmp[0] + tmp[1]
            time += tmp[1]
        } else {
            time += 1
        }
    }

    return ans / jobs.count
}
