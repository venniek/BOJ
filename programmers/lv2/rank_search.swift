import Foundation

func solution(_ info:[String], _ query:[String]) -> [Int] {
    var dict = [String: [Int]]()
    var ans = [Int]()
    
    func make_all(_ arr: [String], _ str: String, _ idx: Int, _ score: Int) {
        if idx == 4 {
            if let _ = dict[str] {
                dict[str]!.append(score)
            } else {
                dict[str] = [Int]()
                dict[str]!.append(score)
            }
            return
        }
        make_all(arr, str + arr[idx], idx + 1, score)
        make_all(arr, str + "-", idx + 1, score)
    }

    for i in info {
        let tmp = i.components(separatedBy: " ")
        let infos = Array(tmp[0...3])
        let score = Int(tmp[4])!
        make_all(infos, "", 0, score)
    }
    let newDict = dict.mapValues { $0.sorted(by: >) }
    for q in query {
        let tmp = q.components(separatedBy: " ").filter({ return $0 != "and"})
        let str = Array(tmp[0...3]).joined(separator: "")
        let score = Int(tmp[4])!
        if let candi = newDict[str] {
            var start = 0, end = candi.count - 1, mid = 0
            while start < end {
                mid = (start + end) / 2
                if candi[mid] >= score {
                    start = mid + 1
                } else {
                    end = mid
                }
            }
            if candi[start] >= score {
                ans.append(start + 1)
            } else {
                ans.append(start)
            }
        } else {
            ans.append(0)
        }
    }
    return ans
}
